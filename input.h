#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>

class Input {
  public:
    static const char* param_names[];
    int a, b, c, d;

    Input();
    ~Input() {}

    void process_param_file(const char* filename);

    void print_state();
};
