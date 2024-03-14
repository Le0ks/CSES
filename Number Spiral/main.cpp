#include <iostream>
#include <algorithm>

#define ll long long

int main() {
    int t; std::cin >> t;
    ll x, y;
    for (int i = 0; i != t; ++i) {
        std::cin >> y >> x;
        if (
            (x % 2 == 1 && std::max(x, y) == x)
            || (y % 2 == 0 && std::max(x, y) == y)
        ) {
            std::cout << std::max(x, y) * std::max(x, y) - (std::min(x, y) - 1) << "\n";
        } else {
            std::cout << std::max(x, y) * std::max(x, y) - 2 * (std::max(x, y) - 1) + (std::min(x, y) - 1) << "\n";
        }
    }
}
