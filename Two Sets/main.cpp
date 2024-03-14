#include <iostream>

#define ll long long

int main() {
    ll n; std::cin >> n;
    if (n * (n + 1) / 2 % 2 == 0) {
        std::cout << "YES\n";
        if (n % 2 == 0) {
            std::cout << n / 2 << "\n";
            for (int i = 1; i != n / 4 + 1; ++i) {
                std::cout << i << " " << n - (i - 1) << " ";
            }
            std::cout << "\n" << n / 2 << "\n";
            for (int i = n / 4 + 1; i != n / 2 + 1; ++i) {
                std::cout << i << " " << n - (i - 1) << " ";
            }
        } else {
            std::cout << (n + 1) / 2 << "\n";
            for (int i = (n + 1) / 4; i != 3 * (n + 1) / 4; ++i) {
                std:: cout << i << " ";
            }
            std::cout << "\n" << (n - 1) / 2 << "\n";
            std::cout << n << " ";
            for (int i = 1; i != (n + 1) / 4; ++i) {
                std::cout << i << " " << n - i << " ";
            }
        }
    } else {
        std::cout << "NO";
    }
}