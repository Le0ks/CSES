#include <iostream>

#define ll long long

int main() {
  int n;
  std::cin >> n;
  ll x[n];
  for (int i = 0; i != n; ++i) {
    std::cin >> x[i];
  }
  ll now_max = 0;
  ll ans = x[0];
  for (int i = 0; i != n; ++i) {
    now_max = now_max + x[i];
    if (now_max > ans) {
      ans = now_max;
    }
    if (now_max < 0) {
      now_max = 0;
    }
  }
  std::cout << ans << '\n';
  return 0;
}
