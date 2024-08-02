#include <algorithm>
#include <iostream>
#include <vector>

#define ll long long

int main() {
  int n;
  std::cin >> n;
  std::vector<ll> p(n);
  for (int i = 0; i != n; ++i) {
    std::cin >> p[i];
  }
  std::sort(p.begin(), p.end());
  ll ans = 0;
  for (int i = 0; i != n; ++i) {
    ans += std::abs(p[i] - p[n / 2]);
  }
  std::cout << ans << '\n';
  return 0;
}
