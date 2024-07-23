#include <iostream>
#include <map>

int main() {
  int n, x;
  std::cin >> n >> x;
  int a[n];
  for (int i = 0; i != n; ++i) {
    std::cin >> a[i];
  }
  std::map<int, int> m;
  for (int i = 0; i != n; ++i) {
    if (m.find(x - a[i]) != m.end()) {
      std::cout << m[x - a[i]] + 1 << " " << i + 1 << '\n';
      return 0;
    }
    m[a[i]] = i;
  }
  std::cout << "IMPOSSIBLE";
  return 0;
}
