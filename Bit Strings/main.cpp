#include <iostream>

int main() {
    int n; std::cin >> n;
    int ans = 1;
    for (int i = 1; i != n + 1; ++i) {
        ans *= 2;
        ans %= 1000000007;
    }
    std::cout << ans;
}