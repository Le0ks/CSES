#include <iostream>
#include <unordered_set>


int main() {
    int n; std::cin >> n;
    std::unordered_set<int> set;
    int el;
    for (int i = 0; i != n - 1; ++i) {
        std::cin >> el;
        set.insert(el);
    }
    for (int i = 0; i != n; ++i) {
        if (set.find(i + 1) == set.end()) {
            std::cout << i + 1;
            break;
        }
    }
}