#include <iostream>
#include <vector>

#define ll long long

int main() {
  int n;
  ll MOD = 1e9 + 7;
  std::cin >> n;
  std::vector<ll> dp(n + 1);
  dp[0] = 1;
  for (int i = 1; i != n + 1; ++i) {
    for (int j = 1; j != 7 && i - j >= 0; ++j) {
      dp[i] = (dp[i] + dp[i - j]) % MOD;
    }
  }
  std::cout << dp[n] << '\n';
  return 0;
}
