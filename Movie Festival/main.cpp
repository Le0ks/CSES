#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

int main (){
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> films(n);
  for (int i = 0; i != n; ++i) {
    std::cin >> films[i].second >> films[i].first;
  }
  std::sort(films.begin(), films.end());
  int count = 0;
  int time = 0;
  for (int i = 0; i != n; ++i) {
    if (time <= films[i].second) {
      time = films[i].first;
      ++count;
    }
  }
  std::cout << count << '\n';
  return 0;
}

