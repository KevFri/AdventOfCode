#include <fmt/core.h>

#include <filesystem>
#include <fstream>
#include <functional>
#include <string>
#include <vector>

#define DEBUG 0

void debug(std::string str) {
#if DEBUG
  fmt::print("{}", str);
#endif
}

[[nodiscard]] const std::vector<std::string> getInput(
    std::filesystem::path fname) {
  auto ifs = std::ifstream{fname};

  auto vec = std::vector<std::string>{};

  std::string line;
  while (std::getline(ifs, line)) {
    vec.emplace_back(line);
  }
  return vec;
}

int main() {
  const auto lines = getInput("input/input04.txt");
  int sum = 0;
  for (const auto& line : lines) {
    int start1, end1, start2, end2;
    sscanf(line.c_str(), "%d-%d,%d-%d", &start1, &end1, &start2, &end2);
    bool included =
        (start1 >= start2 && end1 <= end2) | (start2 >= start1 && end2 <= end1);
    debug(fmt::format("{:40}{}\n", line, included));
    sum += included ? 1 : 0;
  };
  fmt::print("{}\n", sum);
}