#include <algorithm>
#include <iostream>

int main() {
  int n, x;
  std::cin >> n >> x;
  int h[n], s[n];
  for (int i = 0; i != n; ++i) {
    std::cin>> h[i];
  }
  for (int i = 0; i != n; ++i) {
    std::cin >> s[i];
  }
  int dp[x + 1];
  std::fill(dp, dp + x + 1, 0);
  for (int i = 0; i != n; ++i) {
    for (int j = x; j >= h[i]; --j) {
      dp[j] = std::max(dp[j], dp[j - h[i]] + s[i]);
    }
  }
  std::cout << dp[x] << '\n';
  return 0;
}
