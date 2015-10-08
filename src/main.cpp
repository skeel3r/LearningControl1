/*
 * Neural Network for training on CSV files.
 *
 *
 *
 */


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <time.h>
#include "NeuralNet.hpp"
#include "ImportCSV.hpp"

int main(){
  std::string file_name;
  std::string input;
  std::cout << "SPECIFY DATA SET?" << std::endl;
  std::cin >> input;
  if(input == "y" || input == "Y"){
  std::cout << "PLEASE ENTER FILE NAME IN DATA FOLDER" << std::endl;
  std::cin >> file_name;
  }
  else{
    file_name = "train1";
  }
  file_name = "../data/" + file_name + ".csv";



  std::vector<std::vector<double>> csv_data;
  csv_data = importCSV(file_name);
  std::cout << csv_data.size() << std::endl;
  std::cout << "Starting" << std::endl;


  srand(time(NULL));

  NN myNN(5, 4, 2);

  std::cout << "Training" << std::endl;
  myNN.train(csv_data);

  std::cout << "Running" << std::endl;
  std::cout << "Finished" << std::endl;
}
