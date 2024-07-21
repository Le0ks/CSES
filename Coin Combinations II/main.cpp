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
  for (int i = 0; i != n; ++i) {
    if (c[i] < x + 1) {
      for (int j = c[i]; j != x + 1; ++j) {
        dp[j] = (dp[j] + dp[j - c[i]]) % MOD;
      }
    }
  }
  std::cout << dp[x] << '\n';
  return 0;
}
