#include <algorithm>
#include <iostream>

int main() {
  int n, x;
  std::cin >> n >> x;
  int c[n];
  for (int i = 0; i != n; ++i) {
    std::cin >> c[i];
  }
  int dp[x + 1];
  std::fill(dp, dp + x + 1, -1);
  dp[0] = 0;
  for (int i = 0; i != n; ++i) {
    if (c[i] <= x) {
      dp[c[i]] = 1;
    }
  }
  for (int i = 1; i != x + 1; ++i) {
    for (int j = 0; j != n; ++j) {
      if (dp[i] == -1 && i - c[j] >= 0 && dp[i - c[j]] != -1) {
        dp[i] = dp[i - c[j]] + 1;
      } else if (dp[i] != -1 && i - c[j] >= 0 && dp[i - c[j]] != -1) {
        dp[i] = std::min(dp[i], dp[i - c[j]] + 1);
      }
    }
  }
  std::cout << dp[x] << '\n';
  /*for (int i = 0; i != x + 1; ++i) {*/
  /*  std::cout << dp[i] << ' ';*/
  /*}*/
  /*return 0;*/
}
