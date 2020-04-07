#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0423"
#include "../../graph/dijkstra.hpp"
#include <iostream>

int main()
{
    int n, r;
    std::cin >> n >> r;
    std::vector<int> t(n), e(n);
    for (size_t i = 0; i < n; i++) {
        std::cin >> t[i] >> e[i];
    }

    Dijkstra<long> dijkstra(n + 1);
    for (size_t i = 0; i < r; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        a--;
        b--;
        c--;
        dijkstra.add(b, a, c);
    }
    for (size_t i = 0; i < n; i++) {
        dijkstra.add(n, i, t[i]);
    }
    auto d = dijkstra.solve(n);

    long ans = 0;
    for (size_t i = 0; i < n; i++) {
        ans += d[i] * e[i];
    }
    std::cout << ans << std::endl;
}