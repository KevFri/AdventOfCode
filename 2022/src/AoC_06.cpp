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
  const auto lines = getInput("input/input06.txt");

  for (const auto& line : lines) {
    for (size_t n = 0; n < line.size() - 3; n++) {
      auto str = line.substr(n, 4);
      debug(fmt::format("{}\n", str));

      bool unique = true;
      for (size_t i = 0; i < 4; ++i) {
        for (size_t j = 0; j < 4; ++j) {
          if (i != j) {
            if (str[i] == str[j]) {
              unique = false;
            }
          }
        }
      }
      if (unique) {
        fmt::print("{}\n", n + 4);
        break;
      }
    }
  };
}