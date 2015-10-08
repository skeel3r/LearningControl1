#include <vector>
#include "Node.hpp"
#ifndef NEURALNET_HPP
#define NEURALNET_HPP
class NN{
  public:
    NN(int, int, int);
    void train(std::vector<std::vector<double>>);
  private:
    std::vector<Node> nodes;
    int input_size;
    int hidden_size;
    int output_size;
};

#endif
