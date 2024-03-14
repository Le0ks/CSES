#include <iostream>
#include <algorithm>

int main() {
    int t; std::cin >> t;
    int a, b;
    for (int i = 0; i != t; ++i) {
        std::cin >> a >> b;
        if ((a + b) % 3 == 0 && std::min(a, b) - (a + b) / 3 >= 0) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
}