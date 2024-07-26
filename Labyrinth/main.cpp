#include <iostream>
#include <algorithm>
#include <iterator>
#include <utility>
#include <vector>
#include <queue>

std::vector<char> bfs (
  std::vector<std::vector<bool>> &labyrinth,
  std::pair<int, int> start,
  std::pair<int, int> end,
  std::vector<std::vector<char>> &moves,
  std::vector<std::vector<bool>> &used
) {
  bool flag = false;
  std::vector<char> ans_move;
  moves[start.first][start.second] = 'S';
  std::queue<std::pair<int, int>> q;
  q.push(start);
  used[start.first][start.second] = true;
  while (!q.empty()) {
    auto v = q.front();
    q.pop();
    if (v.first == end.first && v.second == end.second) {
      flag = true;
      break;
    }
    if (
      v.first - 1 >= 0
      && labyrinth[v.first - 1][v.second]
      && !used[v.first - 1][v.second]
    ) {
      moves[v.first - 1][v.second] = 'U';
      used[v.first - 1][v.second] = true;
      q.push(std::make_pair(v.first - 1, v.second));
    }
    if (
      v.first + 1 < (int)labyrinth.size()
      && labyrinth[v.first + 1][v.second]
      && !used[v.first + 1][v.second]
    ) {
      moves[v.first + 1][v.second] = 'D';
      used[v.first + 1][v.second] = true;
      q.push(std::make_pair(v.first + 1, v.second));
    }
    if (
      v.second - 1 >= 0
      && labyrinth[v.first][v.second - 1]
      && !used[v.first][v.second - 1]
    ) {
      moves[v.first][v.second - 1] = 'L';
      used[v.first][v.second - 1] = true;
      q.push(std::make_pair(v.first, v.second - 1));
    }
    if (
      v.second + 1 < (int)labyrinth[0].size()
      && labyrinth[v.first][v.second + 1]
      && !used[v.first][v.second + 1]
    ) {
      moves[v.first][v.second + 1] = 'R';
      used[v.first][v.second + 1] = true;
      q.push(std::make_pair(v.first, v.second + 1));
    }
  }
  if (flag) {
    int i = end.first;
    int j = end.second;
    while (moves[i][j] != 'S') {
      ans_move.push_back(moves[i][j]);
      if (moves[i][j] == 'U') {
        i++;
      } else if (moves[i][j] == 'D') {
        i--;
      } else if (moves[i][j] == 'L') {
        j++;
      } else if (moves[i][j] == 'R') {
        j--;
      }
    }
    std::reverse(ans_move.begin(), ans_move.end());
  }
  return ans_move;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<bool>> labyrinth(n, std::vector<bool>(m));
  std::pair<int, int> start, end;
  char c;
  for (int i = 0; i != n; ++i) {
    for (int j = 0; j != m; ++j) {
      std::cin >> c;
      if (c == '#'){
        labyrinth[i][j] = false;
      } else {
        labyrinth[i][j] = true;
      }
      if (c == 'A') {
        start = std::make_pair(i, j);
      } else if (c == 'B') {
        end = std::make_pair(i, j);
      }
    }
  }
  std::vector<std::vector<char>> moves(n, std::vector<char>(m, ' '));
  std::vector<std::vector<bool>> used(n, std::vector<bool>(m));
  std::vector<char> move = bfs(labyrinth, start, end, moves, used);
  if (!move.empty()) {
    std::cout << "YES" << '\n';
    std::cout << move.size() << '\n';
    for (auto i : move) {
      std::cout << i;
    }
    std::cout << '\n';
  } else {
    std::cout << "NO" << '\n';
  }
  return 0;
}
