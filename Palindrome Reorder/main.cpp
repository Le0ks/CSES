#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
  string s; getline(cin, s);
  map<char, int> mp;
  for (char el : s) {
    mp[el]++;
  }
  string res;
  char mid_char = 0;
  for (auto el : mp) {
    if (el.second % 2) {
      if (mid_char) {
        cout << "NO SOLUTION";
        return 0;
      }
      mid_char = el.first;
    }
    for (int i = 0; i < el.second/2; ++i) {
      res += el.first;
    }
  }
  cout << res;
  if (mid_char) {
    cout << mid_char;
  }
  for (int i = res.size()-1; i != -1; i--) {
      cout << res[i];
  }
  return 0;
}
