#include <iostream>

int main() {
    int n; std::cin >> n;
    if (n == 1) {
        std::cout << 1;
    }
    else if (n < 4) {
        std::cout << "NO SOLUTION";
    } else {
        for (int i = 2; i < n + 1; i += 2) {
            std::cout << i << " ";
        }
        for (int i = 1; i < n + 1; i += 2) {
            std::cout << i << " ";
        }
    }
}