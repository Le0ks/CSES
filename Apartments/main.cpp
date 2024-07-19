#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<int> a(n);
  std::vector<int> b(m);
  for (int i = 0; i != n; ++i) {
    std::cin >> a[i];
  }
  for (int i = 0; i != m; ++i) {
    std::cin >> b[i];
  }
  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());
  int count = 0;
  int i = 0, j = 0;
  while (i < n && j < m) {
    if (std::abs(a[i] - b[j]) <= k) {
      ++i;
      ++j;
      ++count;
    } else {
      if (a[i] - b[j] > k) {
        ++j;
      } else {
        ++i;
      }
    }
  }
  std::cout << count << '\n';
  return 0;
}
