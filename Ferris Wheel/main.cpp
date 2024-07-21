#include <algorithm>
#include <iostream>

#define ll long long

bool cmp(ll x, ll y) {
  return x >= y;
}

int main() {
  int n, x;
  std::cin >> n >> x;
  ll p[n];
  for (int i = 0; i != n; ++i) {
    std::cin >> p[i];
  }
  std::sort(p, p + n, cmp);
  bool used[n];
  std::fill(used, used + n, false);
  int count = 0;
  int k = n - 1;
  for (int i = 0; i != n; ++i) {
    if (used[i]) {
      break;
    }
    used[i] = true;
    if (!used[k] && p[i] + p[k] <= x) {
      used[k] = true;
      k--;
    }
    count++;
  }
  std::cout << count << '\n';
  return 0;
}
