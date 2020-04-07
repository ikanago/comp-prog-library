#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_D"
#include "../../math/combination.hpp"
#include <iostream>
constexpr const int MOD = (int)1e9 + 7;

int main()
{
    int n, k;
    std::cin >> n >> k;
    Combination<MOD> com(2000);
    auto ans = com.C(n + k - 1, k - 1);
    std::cout << ans << std::endl;
}
