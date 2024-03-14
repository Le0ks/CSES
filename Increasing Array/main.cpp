#include <iostream>

#define ll long long

int main() {
    int n; std::cin >> n;
    ll array[n];
    ll ans = 0;
    std::cin >> array[0];
    ll max = array[0];
    for (int i = 1; i != n; ++i) {
        std::cin >> array[i];
        if (max < array[i]) max = array[i];
        if (array[i] < max) {
            ans += max - array[i];
        }
    }
    std::cout << ans;
}
