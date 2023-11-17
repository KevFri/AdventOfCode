#include "tools.h"

#include <fstream>

bool isPrime(unsigned int num) {
  if (num < 2) return false;

  if (num == 2) return true;

  for (decltype(num) i = 2; i < (num / 2 + 1); ++i) {
    if (num % i == 0) {
      return false;
    }
  }
  return true;
}

const std::vector<std::string> getInput(std::filesystem::path fname) {
  auto ifs = std::ifstream{fname};

  auto vec = std::vector<std::string>{};

  std::string line;
  while (std::getline(ifs, line)) {
    vec.emplace_back(line);
  }
  return vec;
}