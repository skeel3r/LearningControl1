#include <node.hpp>
#include <math.h>
Node::Node(){
}
double Node::SigmoidActivationFunction(input){
  double output;
  output = 1/(1+exp(input));
}
