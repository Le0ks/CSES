#include <iostream>
#include <vector>

using ll = long long;

int n;
std::vector<ll> p;

ll solve(ll sum1, ll sum2, int index) {
  if (index == n) {
    return std::abs(sum1 - sum2);
  }
  return std::min(
    solve(sum1 + p[index], sum2, index + 1),
    solve(sum1, sum2 + p[index], index + 1)
  );
}

int main(){ 
  std::cin >> n;
  p.resize(n);
  for (int i = 0; i != n; ++i) {
    std::cin >> p[i];
  }
  ll ans = solve(0, 0, 0);
  std::cout << ans << '\n';
  return 0;
}

