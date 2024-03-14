#include <iostream>

#define ll long long

void function(ll n) {
    if (n == 1) {
        std::cout << " 1";
        return;
    }
    if (n % 2 == 0) {
        std::cout << " " << n;
        function(n / 2);
    } else {
        std::cout << " " << n;
        function(n * 3 + 1);
    }
}

int main() {
    ll n; std::cin >> n;
    std::cout << n;
    if (n == 1) {
        return 0;
    }
    if (n % 2 == 0) {
        function(n / 2);
    } else {
        function(n * 3 + 1);
    }
}
