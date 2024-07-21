#include <algorithm>
#include <iostream>

#define ll long long

int main() {
  int MOD = 1e9 + 7;
  int n, x;
  std::cin >> n >> x;
  int c[n];
  for (int i = 0; i != n; ++i) {
    std::cin >> c[i];
  }
  ll dp[x + 1];
  std::fill(dp, dp + x + 1, 0);
  dp[0] = 1;
  for (int i = 1; i != x + 1; ++i) {
    for (int j = 0; j != n; ++j) {
      if (i - c[j] >= 0) {
        dp[i] = (dp[i] + dp[i - c[j]]) % MOD;
      }
    }
  }
  std::cout << dp[x] << '\n';
  return 0;
}
