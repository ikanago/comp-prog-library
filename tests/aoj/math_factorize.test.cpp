#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_A"
#include "../../math/factorize.hpp"
#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    auto factorized = factorize<int>(n);

    std::cout << n << ":";
    for (const auto& p : factorized) {
        for (size_t i = 0; i < p.second; i++) {
            std::cout << " " << p.first;
        }
    }
    std::cout << std::endl;
}