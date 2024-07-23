#include <algorithm>
#include <iostream>

int main() {
  int n;
  std::cin >> n;
  int arrival_time[n], leaving_time[n];
  for (int i = 0; i != n; ++i) {
    std::cin >> arrival_time[i] >> leaving_time[i];
  }
  std::sort(arrival_time, arrival_time + n);
  std::sort(leaving_time, leaving_time + n);
  int i = 0, j = 0;
  int now_count = 0, max_count = 0;
  while (i != n && j != n) {
    if (arrival_time[i] < leaving_time[j]) {
      ++now_count;
      ++i;
    } else {
      --now_count;
      ++j;
    }
    max_count = std::max(max_count, now_count);
  }
  std::cout << max_count << '\n';
  return 0;
}
