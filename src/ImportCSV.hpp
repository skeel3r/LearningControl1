#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

std::vector<std::vector<double>> importCSV(std::string file_name){
  std::cout << file_name << std::endl;
  std::ifstream myfile(file_name);
  std::vector<std::vector<double>> csvData;

  std::string line;
  while(getline(myfile, line)){
    std::stringstream sep(line);
    std::string field;
    csvData.push_back(std::vector<double>());
    while(getline(sep, field, ',')){
      csvData.back().push_back(stod(field));
    }
  }
  /*
  for(auto row : csvData){
    for (auto field : row) {
      std::cout << field << ' ';
     }
     std::cout << '\n';
  }
  */
  return csvData;
}
