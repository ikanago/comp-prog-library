#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0423"

#include <iostream>
#include "../../graph/dijkstra.hpp"
using namespace std;

int main() {
    int n, r;
    cin >> n >> r;
    vector<int> t(n), e(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> t[i] >> e[i];
    }

    Dijkstra dijkstra(n + 1);
    for (size_t i = 0; i < r; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        c--;
        dijkstra.add(b, a, c);
    }
    for (size_t i = 0; i < n; i++)
    {
        dijkstra.add(n, i, t[i]);
    }
    auto d = dijkstra.solve(n);
    for (auto& x : d) cout << x << " ";
    
    long ans = 0;
    for (size_t i = 0; i < n; i++)
    {
        ans += d[i] * e[i];
    }
    cout << ans << "\n";
}