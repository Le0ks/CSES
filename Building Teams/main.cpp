#include <iostream>
#include <utility>
#include <vector>
#include <map>

bool possible = true;

void dfs(
  int v,
  std::map<int, std::vector<int>> &graph,
  std::vector<bool> &used,
  std::vector<bool> &team
) {
  used[v] = true;
  for (auto u: graph[v]) {
    if (!used[u]) {
      team[u] = !team[v];
      dfs(u, graph, used, team);
    } else if (team[u] == team[v]) {
      possible = false;
    }
  }
}

int main () {
  int n, m;
  std::cin >> n >> m;
  std::map<int, std::vector<int>> graph;
  int a, b;
  for (int i = 0; i != m; ++i) {
    std::cin >> a >> b;
    graph[a - 1].push_back(b - 1);
    graph[b - 1].push_back(a - 1);
  }
  std::vector<bool> used(n, false);
  std::vector<bool> team(n, false);
  for (int i = 0; i != n; ++i) {
    if (!used[i]) {
      dfs(i, graph, used, team);
    }
  }
  if (!possible) {
    std::cout << "IMPOSSIBLE" << '\n';
    return 0;
  } 
  for (int i = 0; i != n; ++i) {
    std::cout << (team[i] ? 1 : 2) << ' ';
  }
  std::cout << '\n';
  return 0;
}
