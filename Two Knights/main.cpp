#include <iostream>

#define ll long long

int main() {
    ll n; std::cin >> n;
    for (ll k = 1; k != n + 1; ++k) {
        std::cout << k * k * (k * k - 1) / 2 - 4 * (k - 1) * (k - 2) << "\n";
    }
}