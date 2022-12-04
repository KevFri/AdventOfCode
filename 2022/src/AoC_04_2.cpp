#include <fmt/core.h>

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
    // parse input start and end
    int start1, end1, start2, end2;
    sscanf(line.c_str(), "%d-%d,%d-%d", &start1, &end1, &start2, &end2);

    // create iota views for each section
    auto sections1 = std::views::iota(start1, end1 + 1);
    auto sections2 = std::views::iota(start2, end2 + 1);

    // search for each element in section1 if it's contained in section 2, stop
    // after the first match (take(1))
    for (auto i : sections1 | std::views::filter([&](const auto i) {
                    return std::ranges::find(sections2, i) != sections2.end();
                  }) | std::views::take(1)) {
      debug(fmt::format("{}-{},{}-{},first match:{}\n", start1, end1, start2,
                        end2, i));
      ++sum;  // increase overlaping pair
    }
  };
  fmt::print("overlap sections: {}\n", sum);
}