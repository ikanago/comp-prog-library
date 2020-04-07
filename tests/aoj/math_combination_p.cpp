#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_B"
#include "../../math/combination.hpp"
#include "../../math/modint.hpp"
#include <iostream>
constexpr const int MOD = (int)1e9 + 7;

int main() {
    int n, k;
    std::cin >> n >> k;
    Combination<ModInt<MOD>> com(1000);
    auto ans = com.P(k, n);
    std::cout << ans << std::endl;
}
