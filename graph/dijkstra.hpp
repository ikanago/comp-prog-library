#include <limits>
#include <queue>
#include <vector>

class Dijkstra {
private:
    struct Edge {
        int to;
        int cost;
    };
    std::vector<std::vector<Edge>> G;
    std::vector<int> d;
    using PII = std::pair<int, int>;

public:
    int n;

    Dijkstra(int size)
    {
        n = size;
        G.resize(n, std::vector<Edge>());
        d.resize(n, std::numeric_limits<int>::max());
    }

    // `from` and `to` must be 0-indexed.
    void add(int from, int to, int cost)
    {
        Edge e = { to, cost };
        G[from].push_back(e);
    }

    std::vector<int> solve(int start)
    {
        // priority queue which stores { minimum cost to Edge i, Edge i}
        std::priority_queue<PII, std::vector<PII>, std::greater<PII>> pq;
        d[start] = 0;
        pq.push({ 0, start });
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            auto current_edge = p.second;
            if (d[current_edge] < p.first)
                continue;
            for (const auto& next_edge : G[current_edge]) {
                if (d[next_edge.to] > d[current_edge] + next_edge.cost) {
                    d[next_edge.to] = d[current_edge] + next_edge.cost;
                    pq.push({ d[next_edge.to], next_edge.to });
                }
            }
        }
        return d;
    }
};