#include <iostream>
#include <vector>
#include "NeuralNet.hpp"
#include "Node.hpp"

NN::NN(int inputs, int hidden_nodes, int output_nodes){
  std::cout << "NN Constructed" << std::endl;
  int num_inputs = inputs;
  input_size = inputs;
  hidden_size = hidden_nodes;
  output_size = output_nodes;
  for(int i = 0; i < (hidden_nodes + output_nodes); i++){
    if( i > hidden_nodes){
      num_inputs = inputs;
    }
    Node N(num_inputs);
    nodes.push_back(N);
  }
}

void NN::train(std::vector<std::vector<double>> data){
  std::cout << data.size() << std::endl;
  int count = 0;
  for(int i = 0; i < data.size(); i++){
    count++;
    std::cout << count << std::endl;
    std::vector<double> input_data;
    std::vector<double> output_data;
    std::vector<double> deltas;
    std::vector<double> errors;
    std::vector<double> hidden_layer;
    std::vector<double> neural_out;
    //Parse data into input and results
    for(int j = 0; j < input_size; j++){
      input_data.push_back(data[i][j]);
    }
    for(int j = (input_size); j < (input_size + output_size); j++){
      output_data.push_back(data[i][j]);
    }

    //Feed-Forward
    for(int j = 0; j < hidden_size; j++){
      hidden_layer.push_back(nodes[j].perceive(input_data));
    }
    for(int j = hidden_size; j < (hidden_size + output_size); j++){
      neural_out.push_back(nodes[j].perceive(hidden_layer));
    }

    //Errors
    for(int j = 0; j < output_size; j++){
      errors.push_back(neural_out[j] - output_data[j]);
      std::cout << "ERRORS: " << errors[j] << std::endl; 
    }

    //Back-Prop
    for(int j = hidden_size; j < (hidden_size + output_size); j++){
      deltas.push_back(nodes[j].back_prop(neural_out));
    }
    for(int j = 0; j < hidden_size; j++){
      nodes[j].back_prop(deltas);
    }
  }
  std::cout << "TRAINED!" << std::endl;
}


/*
Get dimensions of neural network
create nodes for each layer, 

Input dimensions: 5
Hidden layer size: 4
Output dimensions: 2

For each input 
  multiply by weight
*/
