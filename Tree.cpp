#include "Tree.h"

Node::Node(double _xmin, double _xmax, double _ymin, double _ymax, double _zmin, double _zmax) {
  c1 = NULL;
  c2 = NULL;
  c3 = NULL;
  c4 = NULL;
  c5 = NULL;
  c6 = NULL;
  c7 = NULL;
  c8 = NULL;

  p = NULL;

  xmin = _xmin;
  xmax = _xmax;
  ymin = _ymin;
  ymax = _ymax;
  zmin = _zmin;
  zmax = _zmax;

  com = Vector3D<double>(0.0);
  child_mass = -1.0;
}

Node::~Node() {
  delete c1;
  delete c2;
  delete c3;
  delete c4;
  delete c5;
  delete c6;
  delete c7;
  delete c8;
}

Node* which_octant(Node* n, Particle* p) {
  double xmid = (n->xmax + n->xmin)/2.0;
  double ymid = (n->ymax + n->ymin)/2.0;
  double zmid = (n->zmax + n->zmin)/2.0;

  double xpos = p->pos[0];
  double ypos = p->pos[1];
  double zpos = p->pos[2];

  if (zpos >= zmid) {
    if (ypos >= ymid) {
      if (xpos >= xmid) {
        return n->c1;
      }
      else {
        return n->c2;
      }
    }
    else {
      if (xpos >= xmid) {
        return n->c4;
      }
      else {
        return n->c3;
      }
    }
  }
  else {
    if (ypos >= ymid) {
      if (xpos >= xmid) {
        return n->c5;
      }
      else {
        return n->c6;
      }
    }
    else {
      if (xpos >= xmid) {
        return n->c8;
      }
    }
  }
  return n->c7;
}

void split_external_node(Node* n) {
  double xmid = (n->xmax + n->xmin)/2.0;
  double ymid = (n->ymax + n->ymin)/2.0;
  double zmid = (n->zmax + n->zmin)/2.0;
  n->c1 = new Node(xmid, n->xmax, ymid, n->ymax, zmid, n->zmax);
  n->c2 = new Node(n->xmin, xmid, ymid, n->ymax, zmid, n->zmax);
  n->c3 = new Node(n->xmin, xmid, n->ymin, ymid, zmid, n->zmax);
  n->c4 = new Node(xmid, n->xmax, n->ymin, ymid, zmid, n->zmax);
  n->c5 = new Node(xmid, n->xmax, ymid, n->ymax, n->zmin, zmid);
  n->c6 = new Node(n->xmin, xmid, ymid, n->ymax, n->zmin, zmid);
  n->c7 = new Node(n->xmin, xmid, n->ymin, ymid, n->zmin, zmid);
  n->c8 = new Node(xmid, n->xmax, n->ymin, ymid, n->zmin, zmid);
}

void add_particle(Node* n, Particle* p) {
  if (n->c1 == NULL && n->p == NULL) {
    //std::cout << "Adding particle to empty node" << std::endl;
    n->p = p;
    n->child_mass = p->mass;
    n->com = p->pos;
  }
  else if (n->c1 != NULL) {
    //std::cout << "Traverse internal node" << std::endl;
    n->child_mass += p->mass;
    n->com += p->pos*p->mass/n->child_mass;
    Node* insert_node = which_octant(n, p);
    add_particle(insert_node, p);
  }
  else {
    //std::cout << "Reached external node...splitting" << std::endl;
    split_external_node(n);
    Particle* pt = n->p;
    n->p = NULL;
    n->child_mass = p->mass + pt->mass;
    n->com = (p->pos*p->mass+pt->pos*pt->mass)/n->child_mass;
    Node* insert_node_original = which_octant(n, pt);
    Node* insert_node_new = which_octant(n, p);

    insert_node_original->child_mass = pt->mass;
    insert_node_original->com = pt->pos;
    insert_node_original->p = pt;

    add_particle(insert_node_new, p);
  }
}

double max_boxsize(Particle* p, int n_particles) {
  int i;
  double max_boxsize = 0.;
  for (i = 0; i < n_particles; i++) {
    if (p[i].pos[0] > max_boxsize) max_boxsize = p[i].pos[0];
    if (p[i].pos[1] > max_boxsize) max_boxsize = p[i].pos[1];
    if (p[i].pos[2] > max_boxsize) max_boxsize = p[i].pos[2];
  }
  return max_boxsize;
}

Tree::Tree(Particle* p, int _n_particles, double _theta, Physics* _physics) {
  n_particles = _n_particles;
  theta = _theta;
  physics = _physics;

  double box_length = max_boxsize(p, n_particles);
  std::cout << "Constructing tree of boxsize " << box_length << std::endl;
  root = new Node(-box_length, box_length, -box_length, box_length, -box_length, box_length);
  int i;
  for (i = 0; i < n_particles; i++) {
    std::cout << "Add particle " << i << " to tree" << std::endl;
    add_particle(root, &p[i]);
  }
  std::cout << "Tree finished" << std::endl;
}

Tree::~Tree() {
  delete root;
}

void Tree::force_on_helper(Particle* p, Node* n, Vector3D<double> net_force) {
  if (n == NULL || p == NULL) return;
  double s = n->xmax - n->xmin;
  double d = (p->pos - n->com).length();
  if (n->c1 == NULL && n->p != p) {
    net_force += physics->grav_force(p->pos, p->mass, n->com, n->child_mass);
  }
  else if (s/d < theta) {
    std::cout << "Approximating node" << std::endl;
    net_force += physics->grav_force(p->pos, p->mass, n->com, n->child_mass);
  }
  else {
    force_on_helper(p, n->c1, net_force);
    force_on_helper(p, n->c2, net_force);
    force_on_helper(p, n->c3, net_force);
    force_on_helper(p, n->c4, net_force);
    force_on_helper(p, n->c5, net_force);
    force_on_helper(p, n->c6, net_force);
    force_on_helper(p, n->c7, net_force);
    force_on_helper(p, n->c8, net_force);
  }
}

Vector3D<double> Tree::force_on(Particle* p) {
  Vector3D<double> force(0.0);  
  force_on_helper(p, root, force);
  return force;
}
