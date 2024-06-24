#include <iostream>
#include <set>

int main() {
  int n; std::cin >> n;
  std::set<int> s;
  for (int i = 0; i != n; ++i) {
    int t;
    std::cin >> t;
    s.insert(t);
  }
  std::cout << s.size() << '\n';
  return 0;
}
