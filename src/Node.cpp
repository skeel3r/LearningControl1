#include <vector>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Node.hpp"
Node::Node(int num_inputs){
  std::cout << "NODE CONSTRUCTED" << std::endl;
  learning_rate = .1;
  for(int i = 0; i < num_inputs; i++){
    float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    std::cout << r << std::endl;
    weights.push_back(r); 
  }
  float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
  offset_bias = r;
  std::cout << "WEIGHTS GENERATED" << std::endl;
  //random generate weights based on num_inputs
}

double Node::back_prop(std::vector<double> errors){
  //calculate the delta which is based on the output
  double delta;
  for(int i = 0; i < errors.size(); i++){
    delta = errors[i] * y * (1 - y);
  }
  //update weights based on gradient descent
  update_weights(delta);
  return delta;
}

void Node::update_weights(vector<double> delta){
  for(int i = 0; i < weights.size(); i++){
    weights[i] = learning_rate * delta 
  }
 

}
double Node::sigmoid_activation(double input){
  double output;
  output = 1/(1+exp(input));
  return output;
}

double Node::perceive(std::vector<double> inputs){
  double output;
  for(int i; i < inputs.size(); i++){
    output += inputs[i]*weights[i];
  }
  output += offset_bias;
  output = Node::sigmoid_activation(output);
  y = output;
  return output;
}

std::vector<double> Node::get_weights(){
  return weights;
}

double Node::get_bias(){
  return offset_bias;
}
