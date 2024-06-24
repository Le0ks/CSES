#include <algorithm>
#include <iostream>
#include <set>
#include <string>

std::set<std::string> create_strings(std::string s) {
  std::set<std::string> ans;
  for (int i = 0; i != s.size(); ++i) {
    std::set<std::string> cur = create_strings(s.substr(0, i) + s.substr(i + 1, s.size()));
    for (auto str : cur) {
      ans.insert(s[i] + str);    
    }
  }
  return ans;
}

int main() {
  std::string input;
  std::getline(std::cin, input);
  std::sort(input.begin(), input.end());
  std::set<std::string> ans = create_strings(input);
  for(std::string str : ans) {
    std::cout << str << '\n';
  }
  return 0;
}
