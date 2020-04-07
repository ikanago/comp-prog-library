#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_E"
#include "../../math/extgcd.hpp"
#include <iostream>

int main()
{
    int a, b, x, y;
    std::cin >> a >> b;
    extgcd<int>(a, b, x, y);
    std::cout << x << " " << y << std::endl;
}
