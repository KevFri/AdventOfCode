#include <fmt/core.h>

#include <filesystem>
#include <fstream>
#include <string>
#include <vector>

const std::vector<std::string> getInput(std::filesystem::path fname) {
  auto ifs = std::ifstream{fname};

  auto vec = std::vector<std::string>{};

  std::string line;
  while (std::getline(ifs, line)) {
    vec.emplace_back(line);
  }
  return vec;
}

int main() {
  const auto lines = getInput("input/input01.txt");

  for (const auto& line : lines) {
    fmt::print("{}\n", line);
  }
}