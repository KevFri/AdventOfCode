#include <fmt/core.h>

#include <algorithm>
#include <filesystem>
#include <fstream>
#include <functional>
#include <ranges>
#include <string>
#include <vector>

#define DEBUG 0

void debug(std::string str) {
#if DEBUG
  fmt::print("{}", str);
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

struct Elve {
  int num{0};
  int calories{0};
};

constexpr bool operator<(Elve lhs, Elve rhs) {
  return lhs.calories < rhs.calories;
}

int main() {
  const auto lines = getInput("input/input01.txt");

  auto elve = Elve{};
  std::vector<Elve> elves{};
  for (const auto& line : lines) {
    int calories = std::atoi(line.c_str());

    debug(fmt::format("{}\t{}\n", line, calories));

    if (calories != 0) {
      elve.calories += calories;
    } else {
      elve.num = elves.size();
      elves.emplace_back(elve);

      // reset elve and calories
      elve = Elve{};
      calories = 0;
    }
  }

  for (const auto& elve : elves) {
    debug(fmt::format("elve {}\t{}\n", elve.num, elve.calories));
  }

  auto it = std::max_element(begin(elves), end(elves));

  if (it != end(elves)) {
    auto elve = *it;
    fmt::print("max calories elve (num: {}) --> calories: {}\n", elve.num,
               elve.calories);
  }

  std::sort(begin(elves), end(elves));

  for (const auto& elve : elves) {
    debug(fmt::format("elve {:6}\t{}\n", elve.num, elve.calories));
  }
  debug("\n");

  auto calSum = 0;
  for (auto it = std::prev(end(elves), 3); it < end(elves); ++it) {
    auto elve = *it;

    debug(fmt::format("elve {:6}\t{}\n", elve.num, elve.calories));

    calSum += elve.calories;
  };
  fmt::print("Calories sum of top three elves: {}\n", calSum);
}