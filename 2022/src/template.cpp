#include <fmt/core.h>

#include <filesystem>
#include <fstream>
#include <functional>
#include <string>
#include <vector>

#define DEBUG 0

void debug(std::function<void(void)> func) {
#if DEBUG
  func();
#endif
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

int main() {
  const auto lines = getInput("input/input01.txt");

  debug([&] {
    for (const auto& line : lines) {
      fmt::print("{}\n", line);
    }
  });
}