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
  /*
  [J]             [F] [M]
  [Z] [F]     [G] [Q] [F]
  [G] [P]     [H] [Z] [S] [Q]
  [V] [W] [Z] [P] [D] [G] [P]
  [T] [D] [S] [Z] [N] [W] [B] [N]
  [D] [M] [R] [J] [J] [P] [V] [P] [J]
  [B] [R] [C] [T] [C] [V] [C] [B] [P]
  [N] [S] [V] [R] [T] [N] [G] [Z] [W]
   1   2   3   4   5   6   7   8   9
  */
  auto stacks = std::vector<std::vector<char>>{
      std::vector<char>{'N', 'B', 'D', 'T', 'V', 'G', 'Z', 'J'},
      std::vector<char>{'S', 'R', 'M', 'D', 'W', 'P', 'F'},
      std::vector<char>{'V', 'C', 'R', 'S', 'Z'},
      std::vector<char>{'R', 'T', 'J', 'Z', 'P', 'H', 'G'},
      std::vector<char>{'T', 'C', 'J', 'N', 'D', 'Z', 'Q', 'F'},
      std::vector<char>{'N', 'V', 'P', 'W', 'G', 'S', 'F', 'M'},
      std::vector<char>{'G', 'C', 'V', 'B', 'P', 'Q'},
      std::vector<char>{'Z', 'B', 'P', 'N'},
      std::vector<char>{'W', 'P', 'J'}};

  const auto lines = getInput("input/input05.txt");

  for (const auto& line : lines) {
    debug(fmt::format("{}\n", line));
    int cnt, src, dst;
    if (auto ret =
            sscanf(line.c_str(), "move %d from %d to %d", &cnt, &src, &dst);
        ret == 3) {
      --src;
      --dst;
      for (int i = 0; i < cnt; ++i) {
        stacks[dst].emplace_back(stacks[src].back());
        stacks[src].pop_back();
      }
    } else {
      throw std::runtime_error{"error parsing line"};
    }
  };

  for (const auto& stack : stacks) {
    fmt::print("{}", stack.back());
  }
  fmt::print("\n");
}