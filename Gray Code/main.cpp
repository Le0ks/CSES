#include <iostream>
#include <vector>

using namespace std;

#define DEBUG

vector<vector<bool>> print_gray_code(int n) {
  if (n == 1) {
    return {{0}, {1}};
  }
  auto arr = print_gray_code(n - 1);
  vector<vector<bool>> res;
  for (auto& el : arr) {
    el.push_back(0); 
  }
  res = arr;
  for (auto& el : arr) {
    el[n-1] = 1;
  }
  reverse(arr.begin(), arr.end());
  for (const auto& el : arr) {
    res.push_back(el);
  }
  return res;
}

int main() {
  int n; cin >> n;
  auto ans = print_gray_code(n);
  for (int i = 0; i != ans.size(); ++i) {
    for (int j = 0; j != n; ++j) {
      cout << ans[i][j];
    }
    cout << "\n";
  }
  return 0;
}

