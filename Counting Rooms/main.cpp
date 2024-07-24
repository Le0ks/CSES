#include <iostream>
#include <vector>

int n, m;

void dfs(int i, int j, std::vector<std::vector<bool>>& grid, std::vector<std::vector<bool>>& used) {
  used[i][j] = true;
  if (i > 0 && !used[i - 1][j] && grid[i - 1][j]) {
    dfs(i - 1, j, grid, used);
  }
  if (j > 0 && !used[i][j - 1] && grid[i][j - 1]) {
    dfs(i, j - 1, grid, used);
  }
  if (i < n - 1 && !used[i + 1][j] && grid[i + 1][j]) {
    dfs(i + 1, j, grid, used);
  }
  if (j < m - 1 && !used[i][j + 1] && grid[i][j + 1]) {
    dfs(i, j + 1, grid, used);
  }
}

int main() {
  std::cin >> n >> m;
  std::vector<std::vector<bool>> grid(n, std::vector<bool>(m));
  char c;
  for (int i = 0; i != n; ++i) {
    for (int j = 0; j != m; ++j) {
      std::cin >> c;
      if (c == '.') {
        grid[i][j] = true;
      } else {
        grid[i][j] = false;
      }
    }
  }
  std::vector<std::vector<bool>> used(n, std::vector<bool>(m));
  int ans = 0;
  for (int i = 0; i != n; ++i) {
    for (int j = 0; j != m; ++j) {
      if (grid[i][j] && !used[i][j]) {
        ++ans;
        dfs(i, j, grid, used);
      }
    }
  }
  std::cout << ans << '\n';
  return 0;
}
