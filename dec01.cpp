#include <file.h>

int main(int argc, char **argv) {
  std::vector<std::string> fileLines;

  if (argc == 1) {
    std::cout << "Missing input file. Please download the input file as a txt "
                 "and use it as an argument"
              << std::endl;
    return 1;
  } else {
    std::string fileName = argv[1];
    fileLines = getFileLines(fileName);
  }
  long long position = 50;
  long password = 0;
  if (fileLines.size() == 0) {
    return 1;
  }

  for (std::string itr : fileLines) {
    int temp = std::stoi(itr.substr(1, itr.size() - 1));
    if (itr[0] == 'L') {
      position = (((position - temp) % 100) + 100) % 100;
    } else {
      position = (position + temp) % 100;
    }
    if (position == 0) {
      password++;
    }
  }

  std::cout << "Answer: " << password << std::endl;

  return 0;
}
