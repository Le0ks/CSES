#include <algorithm>
#include <iostream>
#include <set>
#include <string>


int main() {
  std::string input;
  std::getline(std::cin, input);
  std::set<std::string> ans;
  std::sort(input.begin(), input.end());
  do {
    ans.insert(input);
  } while (std::next_permutation(input.begin(), input.end()));
  std::cout << ans.size() << '\n';
  for (auto el : ans) {
    std::cout << el << '\n';
  }
  return 0;
}
