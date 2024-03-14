#include <iostream>
// #include <fstream>

int main() {
    // std::ifstream ifs("input.txt");
    // std::cin.rdbuf(ifs.rdbuf());
    char prev_letter = '0', now_letter = '0';
    int max = 1, now = 1;
    while (std::cin >> now_letter) {
        if (now_letter == prev_letter) {
            now++;
        } else {
            if (max < now) max = now;
            now = 1;
        }
        prev_letter = now_letter;
    }
    if (max < now) max = now;
    std::cout << max;
}
