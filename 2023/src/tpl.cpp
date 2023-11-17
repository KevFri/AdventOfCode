#include <fmt/core.h>
#include <stdio.h>

#include <algorithm>
#include <memory>
#include <ranges>

#include "tools.h"

int main() {
  const auto fname = std::filesystem::path{"file.txt"};

  // create dummy data
  auto fp = std::unique_ptr<FILE, int (*)(FILE*)>(fopen(fname.c_str(), "we"),
                                                  &fclose);

  // enumerate view of first 1000 prime numbers starting by 0
  auto view = std::views::iota(0u, std::numeric_limits<unsigned int>::max()) |
              std::ranges::views::filter([](auto e) { return isPrime(e); }) |
              std::ranges::views::take(1e3);
  auto enm = view | std::views::enumerate;

  // evaluate view and print to file
  auto print = [&fp](auto pair) {
    auto [idx, e] = pair;
    fmt::print(fp.get(), "{:7} {}\n", idx + 1, e);
  };
  std::ranges::for_each(enm, print);
  fp.reset();

  // load data
  const auto lines = getInput(fname);

  // cleanup
  std::filesystem::remove(fname);

  // process data
  /*for (const auto [idx, line] : std::views::enumerate(lines)) {
    fmt::print("{} {}\n", idx, line);
  }*/
}