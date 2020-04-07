#define PROBLRM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_A"
#include "../../math/modint.hpp"
#include <iostream>
constexpr const int MOD = (int)1e9 + 7;

int main()
{
    int n, k;
    std::cin >> n >> k;
    ModInt<MOD> mk(k);
    auto ans = mk.pow(n);
    std::cout << ans << std::endl;
}