#ifndef TREE_H
#define TREE_H

#include "Particle.h"
#include "Physics.h"

class Node {
  public:
    Node *c1, *c2, *c3, *c4, *c5, *c6, *c7, *c8;
    Particle* p;
    double xmin, xmax;
    double ymin, ymax;
    double zmin, zmax;
    Vector3D<double> com;
    double child_mass;

    Node(double _xmin, double _xmax, double _ymin, double _ymax, double _zmin, double _zmax);
    ~Node();
};

class Tree {
  public:
    Node* root;
    Physics* physics;
    int n_particles;
    double theta;
    Vector3D<double> force_on(Particle *p);
    Tree(Particle* p, int _n_particles, double _theta, Physics* physics);
    ~Tree();

  private:
    void force_on_helper(Particle* p, Node* n, Vector3D<double>* net_force);
};

#endif
