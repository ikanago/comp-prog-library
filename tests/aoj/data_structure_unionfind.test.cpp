#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_A"
#include "../../data_structure/unionfind.hpp"
#include <iostream>

int main()
{
    int n, q;
    std::cin >> n >> q;
    UnionFind trees(n);
    for (size_t i = 0; i < q; i++) {
        int c, x, y;
        std::cin >> c >> x >> y;
        if (c == 0) {
            trees.unite(x, y);
        } else {
            std::cout << (trees.same(x, y) ? 1 : 0) << std::endl;
        }
    }
}
