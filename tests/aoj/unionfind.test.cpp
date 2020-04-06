#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_A"

#include <iostream>
using namespace std;
#include "../../data-structure/union-find.hpp"

int main() {
    int n, q;
    cin >> n >> q;
    UnionFind trees(n);
    for (size_t i = 0; i < q; i++)
    {
        int c, x, y;
        cin >> c >> x >> y;
        if (c == 0) {
            trees.unite(x, y);
        }
        else {
            cout << (trees.same(x, y) ? 1 : 0) << "\n";
        }
    }
}
