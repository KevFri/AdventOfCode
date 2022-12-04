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

struct Group {
  std::string elve1;
  std::string elve2;
  std::string elve3;
};

int main() {
  const auto lines = getInput("input/input03.txt");

  // sort three lines of elves to a group
  std::vector<Group> groups{};
  Group group;
  for (size_t i = 0; i < lines.size(); ++i) {
    if (i % 3 == 0) {
      group.elve1 = lines[i];
    } else if (i % 3 == 1) {
      group.elve2 = lines[i];
    } else if (i % 3 == 2) {
      group.elve3 = lines[i];
    } else {
      throw std::runtime_error("not reachable");
    }

    if (i % 3 == 2) {
      groups.emplace_back(group);
    }
  }

  // loop over groups and find character which are same in each elve rucksack
  int sum = 0;
  for (const auto& group : groups) {
    // lambda for filtering character in elve2
    const auto find_elve2 = [&](const auto c) {
      return group.elve2.find(c) != std::string::npos;
    };

    // lambda for filtering character in elve3
    const auto find_elve3 = [&](const auto c) {
      return group.elve3.find(c) != std::string::npos;
    };

    // for each character in elve1 filter elve2 and elve3, than take one result
    for (const auto item :
         std::views::all(group.elve1) | std::views::filter(find_elve2) |
             std::views::filter(find_elve3) | std::views::take(1)) {
      // calculate priority and sum up
      auto priority = islower(item) ? (item - 'a' + 1) : (item - 'A' + 27);
      sum += priority;
      debug(fmt::format("{:50}{:50}{:50} {}\n", group.elve1, group.elve2,
                        group.elve3, item));
    }
  }

  fmt::print("sum of priority badge: {}\n", sum);
}