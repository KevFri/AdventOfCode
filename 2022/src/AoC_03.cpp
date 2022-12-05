#include <fmt/core.h>
#include <fmt/ranges.h>

#include <algorithm>
#include <cctype>
#include <filesystem>
#include <fstream>
#include <functional>
#include <ranges>
#include <span>
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
  const auto lines = getInput("input/input03.txt");

  int sum = 0;
  for (const auto& line : lines) {
    auto b = begin(line);
    auto s = line.size();

    auto compartment1 = std::span{b, s / 2};
    auto compartment2 = std::span{std::next(b, s / 2), s / 2};

    char item = ' ';
    std::ranges::for_each(compartment1, [&](auto c) {
      auto it = std::ranges::find(compartment2, c);
      if (it != compartment2.end()) {
        item = *it;
      }
    });
    auto priority = islower(item) ? (item - 'a' + 1) : (item - 'A' + 27);
    sum += priority;

    debug(fmt::format("{:50}{:}   {:}   {:}   {:}   {:}\n", line,
                      fmt::join(compartment1, ""), fmt::join(compartment2, ""),
                      item, priority, sum));
  }
  fmt::print("sum of the priorities: {}\n", sum);
}