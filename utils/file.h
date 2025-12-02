#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> getFileLines(std::string file) {
  std::vector<std::string> fileLines;
  std::string line;
  std::ifstream inputFile(file);
  if (!inputFile.is_open()) {
    std::cout << "ERROR: File not opened" << std::endl;
    return fileLines;
  }

  while (std::getline(inputFile, line)) {
    fileLines.push_back(line);
  }

  inputFile.close();

  return fileLines;
}
