#include <vector>
#ifndef NODE_HPP
#define NODE_HPP
class Node{
  public:
    Node(int);
    double perceive(std::vector<double> inputs);
    double back_prop(std::vector<double> errors);
    double sigmoid_activation(double input);
    std::vector<double> get_weights();
    double get_bias();
  private:
    std::vector<double> weights;
    double offset_bias;
    double learning_rate;
    double y;
};
#endif
