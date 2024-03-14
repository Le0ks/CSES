#include <iostream>
#include <map>
#include <set>
#include <vector>

std::map<std::pair<int, int>, std::set<std::pair<int, int>>> graph;
std::vector<std::vector<bool>> used;

void dfs(std::pair<int, int> v) {
    if (!used[v.first][v.second]) {
        used[v.first][v.second] = true;
        for (auto u : graph[v]) {
            dfs(u);
        }
    }
}

int countConnectedComponents() {
    int count = 0;
    for (auto& v: graph) {
        if (!used[v.first.first][v.first.second]) {
            dfs(v.first);
            count++;
        }
    }
    return count;
}

int main() {
    int n, m; std::cin >> n >> m;
    used.resize(n, std::vector<bool>(m, false));
    char table[n][m];
    std::pair<int, int> v, prev_v;
    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != m; ++j) {
            std::cin >> table[i][j];
            if (table[i][j] == '.') {
                v = {i, j};
                graph[v] = {};
                if (j != 0 && table[i][j - 1] == '.') {
                    prev_v = {i, j - 1};
                    graph[v].insert(prev_v);
                    graph[prev_v].insert(v);
                }
            }
        }
    }
    for (int j = 0; j != m; ++j) {
        for (int i = 0; i != n; ++i) {
            if (table[i][j] == '.') {
                v = {i, j};
                if (i != 0 && table[i - 1][j] == '.') {
                    prev_v = {i - 1, j};
                    graph[v].insert(prev_v);
                    graph[prev_v].insert(v);
                }
            }
        }
    }
    std::cout << countConnectedComponents();
}