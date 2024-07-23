#include <algorithm>
#include <iostream>

int main() {
  int n;
  std::cin >> n;
  int dp[n + 1];
  std::fill(dp, dp + n + 1, 1e9);
  dp[0] = 0;
  for (int i = 1; i != n + 1; ++i) {
    int t = i;
    while (t) {
      int d = t % 10;
      if (i - d >= 0) {
        dp[i] = std::min(dp[i], dp[i - d] + 1);
      }
      t /= 10;
    }
  }
  std::cout << dp[n] << '\n';
  return 0;
}
