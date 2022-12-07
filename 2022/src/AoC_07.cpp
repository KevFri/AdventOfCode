#include <fmt/core.h>

#include <filesystem>
#include <fstream>
#include <functional>
#include <map>
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
  std::map<std::filesystem::path, int> dirs{};
  const auto lines = getInput("input/input07.txt");
  std::filesystem::path path;
  int folderSize = 0;
  for (const auto& line : lines) {
    // debug(fmt::format("{}\n", line));
    char diff[100];
    char fname[100];
    int size{0};
    if (line == "$ ls") {
      folderSize = 0;
    } else if (sscanf(line.c_str(), "$ cd %s", diff) == 1) {
      if (std::string{diff} == "..") {
        path = path.parent_path();
      } else {
        path /= diff;
      }
      // debug(fmt::format("path changed to: {}\n", path.c_str()));
    } else if (sscanf(line.c_str(), "%d %s", &size, fname)) {
      auto file = path / fname;
      folderSize += size;
      debug(fmt::format("{:60} {:60} {} {}\n", path.c_str(), file.c_str(), size,
                        folderSize));
      dirs[path] = folderSize;
    }
  }

  for (const auto& [path2, size] : dirs) {
    for (const auto& [path3, size3] : dirs) {
      if (path2 != path3) {
        std::size_t found = std::string{path3.c_str()}.find(path2);
        if (found != std::string::npos) {
          // fmt::print("{} in {}\n", path3.c_str(), path2.c_str());
          dirs[path2] += size3;
        }
      }
    }
  }

  size_t sum = 0;
  for (const auto& [path2, size2] : dirs) {
    // fmt::print("{} {}\n", path2.c_str(), size);
    if (size2 <= 100000) {
      sum += size2;
    }
  }

  auto deleteDirSize{30000000};
  auto total = dirs["/"];
  for (const auto& [path2, size2] : dirs) {
    if (size2 >= (total - 40000000))
      deleteDirSize = std::min(deleteDirSize, size2);
  }
  // std::cout << p1 << std::endl;

  fmt::print("{}\n", sum);
  fmt::print("{}\n", deleteDirSize);
}