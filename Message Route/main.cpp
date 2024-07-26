#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <queue>

std::vector<int> bfs(
  int start,
  int end,
  std::map<int, std::vector<int>> &graph,
  std::vector<bool> &used
) {
  std::map<int, int> parent;
  used[start] = true;
  std::queue<int> q;
  q.push({start});
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    if (v == end) {
      std::vector<int> path;
      path.push_back(v);
      while (v != start) {
        v = parent[v];
        path.push_back(v);
      }
      std::reverse(path.begin(), path.end());
      return path;
    }
    for (auto n : graph[v]) {
      if (!used[n]) {
        parent[n] = v;
        q.push(n);
        used[n] = true;
      }
    }
  }
  return {};
}

int main() {
  int n, m;
  std::cin >> n >> m;
  int a, b;
  std::map<int, std::vector<int>> graph;
  for (int i = 0; i < m; ++i) {
    std::cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  int start = 1, end = n;
  std::vector<bool> used(n + 1, false);
  std::vector<int> path = bfs(start, end, graph, used);
  if (path.empty()) {
    std::cout << "IMPOSSIBLE";
  } else {
    std::cout << path.size() << '\n';
    for (int i = 0; i != (int)path.size(); ++i) {
      std::cout << path[i] << ' ';
    }
    std::cout << '\n';
  }
}
