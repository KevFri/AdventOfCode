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
enum class Shape : int { Rock = 1, Paper = 2, Scissors = 3 };
Shape from_value(char c) {
  if (c == 'A' || c == 'X') {
    return Shape::Rock;
  }
  if (c == 'B' || c == 'Y') {
    return Shape::Paper;
  }
  if (c == 'C' || c == 'Z') {
    return Shape::Scissors;
  }
  return Shape::Paper;
}
std::string to_string(Shape shape) {
  switch (shape) {
    case Shape::Paper:
      return "Paper";
    case Shape::Scissors:
      return "Scissors";
    case Shape::Rock:
      return "Rock";
  }
  throw std::runtime_error("Shape not valid");
}
enum class Winner { Player = 6, Opponent = 0, Draw = 3 };
std::string to_string(Winner shape) {
  switch (shape) {
    case Winner::Player:
      return "Player";
    case Winner::Opponent:
      return "Opponent";
    case Winner::Draw:
      return "Draw";
  }
  throw std::runtime_error("Winner not valid");
}
namespace winner {
Winner from_value(char c) {
  if (c == 'X') {
    return Winner::Opponent;
  }
  if (c == 'Y') {
    return Winner::Draw;
  }
  if (c == 'Z') {
    return Winner::Player;
  }
  throw std::runtime_error("Winner char not valid");
}
}  // namespace winner

/**
 * @brief calculates winner of two shapes
 *
 * @param player player shape
 * @param opponent opponent shape
 * @return winner
 */
Winner game(Shape player, Shape opponent) {
  if (player == opponent) {
    return Winner::Draw;
  };
  using enum Shape;
  if (player == Rock && opponent == Paper) {
    return Winner::Opponent;
  }
  if (player == Rock && opponent == Scissors) {
    return Winner::Player;
  }

  if (player == Paper && opponent == Rock) {
    return Winner::Player;
  }
  if (player == Paper && opponent == Scissors) {
    return Winner::Opponent;
  }

  if (player == Scissors && opponent == Rock) {
    return Winner::Opponent;
  }
  if (player == Scissors && opponent == Paper) {
    return Winner::Player;
  }

  throw std::runtime_error("Game not implemented");
}

/**
 * @brief choose the shape of the player to score the given winner by given
 * opponent shape
 *
 * @param opponent opponent shape
 * @param winner result of the match
 * @return Shape of the player for given match result
 */
Shape game2(Shape opponent, Winner winner) {
  if (winner == Winner::Draw) {
    return opponent;
  };
  using enum Shape;
  using enum Winner;

  if (opponent == Scissors && winner == Opponent) {
    return Paper;
  }
  if (opponent == Scissors && winner == Player) {
    return Rock;
  }
  if (opponent == Rock && winner == Opponent) {
    return Scissors;
  }
  if (opponent == Rock && winner == Player) {
    return Paper;
  }
  if (opponent == Paper && winner == Opponent) {
    return Rock;
  }
  if (opponent == Paper && winner == Player) {
    return Scissors;
  }

  throw std::runtime_error("Game not implemented");
}

struct Game {
  Shape player;
  Shape opponent;
  Winner winner;

  // constructor for game 1
  Game(Shape player, Shape opponent) : player(player), opponent(opponent) {
    winner = game(player, opponent);
  }

  // constructor for game 2
  Game(Shape opponent, Winner winner) : player(player), winner(winner) {
    player = game2(opponent, winner);
  }
};

int main() {
  const auto lines = getInput("input/input02.txt");
  std::vector<Game> games{};
  std::vector<Game> games2{};

  for (const auto& line : lines) {
    char player;
    char opponent;
    sscanf(line.c_str(), "%c %c", &opponent, &player);

    // calculate game 1
    games.emplace_back(Game(from_value(player), from_value(opponent)));

    // calculate game 2
    games2.emplace_back(
        Game(from_value(opponent), winner::from_value(player /*win*/)));
  }

  int score{0};
  std::ranges::for_each(games, [&](const Game& game) {
    score += static_cast<int>(game.player) + static_cast<int>(game.winner);
  });
  fmt::print("Total score #1: {}\n", score);

  score = 0;
  std::ranges::for_each(games2, [&](const Game& game) {
    score += static_cast<int>(game.player) + static_cast<int>(game.winner);
  });

  fmt::print("Total score #2: {}\n", score);
}