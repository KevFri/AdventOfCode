#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <ranges>

#include "tools.h"

TEST_CASE("Test isPrime", "aoc2023") {
  CHECK_FALSE(isPrime(0u));

  std::vector allPrimesTo100{2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
                             43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

  for (const unsigned int num : std::views::iota(0u, 100u)) {
    INFO(num);
    if (std::ranges::find(allPrimesTo100, num) != allPrimesTo100.end()) {
      CHECK(isPrime(num));
    } else {
      CHECK_FALSE(isPrime(num));
    }
  }
}
