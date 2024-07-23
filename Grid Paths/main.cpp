#include <algorithm>
#include <iostream>

#define ll long long

int MOD = 1e9 + 7;

int main() {
  int n;
  std::cin >> n;
  bool grid[n][n];
  char c;
  for (int i = 0; i != n; ++i) {
    for (int j = 0; j != n; ++j) {
      std::cin >> c;
      if (c == '.') {
        grid[i][j] = false;
      } else {
        grid[i][j] = true;
      }
    }
  }
  if (grid[n - 1][n - 1]) {
    std::cout << 0 << '\n';
    return 0;
  }
  ll dp[n + 1][n + 1];
  for (int i = 0; i != n + 1; ++i) {
    std::fill(dp[i], dp[i] + n + 1, 0);
  }
  for (int i = 1; i != n + 1; ++i) {
    for (int j = 1; j != n + 1; ++j) {
      if (i == 1 && j == 1) {
        dp[i][j] = (!grid[i - 1][j - 1]) ? 1 : 0;
      } else if (i == 1) {
        dp[i][j] = (!grid[i - 1][j - 2]) ? dp[i][j - 1] : 0;
      } else if (j == 1) {
        dp[i][j] = (!grid[i - 2][j - 1]) ? dp[i - 1][j] : 0;
      } else {
        dp[i][j] = (
          ( (!grid[i - 2][j - 1]) ? dp[i - 1][j] : 0 )
          + ( (!grid[i - 1][j - 2]) ? dp[i][j - 1] : 0 )
        ) % MOD;
      }
    }
  }
  std::cout << dp[n][n] % MOD << '\n';
  return 0;
}
