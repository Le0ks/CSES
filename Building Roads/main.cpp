#include <iostream>
#include <utility>
#include <vector>
#include <map>

void dfs(
  int i, std::map<int,
  std::vector<int>>& graph,
  std::vector<bool>& used
) {
  used[i] = true;
  for (auto j : graph[i]) {
    if (!used[j]) {
      dfs(j, graph, used);
    }
  }
}

int main() {
  int n, m;
  std::cin >> n >> m;
  std::map<int, std::vector<int>> graph;
  int a, b;
  for (int i = 0; i != m; ++i) {
    std::cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  std::vector<bool> used(n + 1, false);
  std::vector<int> roads;
  for (int i = 1; i != n + 1; ++i) {
    if (!used[i]) {
      roads.push_back(i);
      dfs(i, graph, used);
    }
  }
  std::cout << roads.size() - 1 << '\n';
  for (int i = 0; i != (int)roads.size() - 1; ++i) {
    std::cout << roads[i] << ' ' << roads[i + 1] << '\n';
  }
  return 0;
}
