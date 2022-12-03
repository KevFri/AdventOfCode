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

  auto sum = 0;
  for (const auto& group : groups) {
    debug(fmt::format("{:50}{:50}{:50}\n", group.elve1, group.elve2,
                      group.elve3));

    char item = ' ';
    std::ranges::for_each(group.elve1, [&](auto c) {
      auto it = std::ranges::find(group.elve2, c);
      if (it != group.elve2.end()) {
        auto it2 = std::ranges::find(group.elve3, *it);
        if (it2 != group.elve3.end()) {
          debug(fmt::format("{}\n", *it2));
          item = *it2;
        }
      }
    });
    auto priority = islower(item) ? (item - 'a' + 1) : (item - 'A' + 27);
    sum += priority;
    debug("\n");
  }
  fmt::print("sum of priority badge: {}\n", sum);
}