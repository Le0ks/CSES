#include <iostream>

int main() {
    int n; std::cin >> n;
    int count = 0;
    for (int i = 5; n / i >= 1; i *= 5) { // считаем сколько раз встретилось 5 ** k
        count += n / i;
    }
    std::cout << count;
}
