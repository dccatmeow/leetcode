#include <bits/stdc++.h>
using namespace std;

class FordFulkerson {
private:
    int n;

    // Residual capacity.
    vector<vector<int>> capacity;

    // Adjacency list.
    // Contains both forward and reverse directions.
    vector<vector<int>> adj;

    int dfs(
        int u,
        int sink,
        int flow,
        vector<bool>& path
    ) {
        // Reached the sink.
        if (u == sink) {
            return flow;
        }

        // Mark this node as part of the current search.
        path[u] = true;

        for (int v : adj[u]) {

            // Can we use this edge?
            if (!path[v] && capacity[u][v] > 0) {

                int pushed = dfs(
                    v,
                    sink,
                    min(flow, capacity[u][v]),
                    path
                );

                if (pushed > 0) {

                    // Reduce forward residual capacity.
                    capacity[u][v] -= pushed;

                    // Increase reverse residual capacity.
                    capacity[v][u] += pushed;

                    return pushed;
                }
            }
        }

        return 0;
    }

public:
    FordFulkerson(int n) : n(n) {
        capacity.assign(n, vector<int>(n, 0));
        adj.resize(n);
    }

    void addEdge(int u, int v, int cap) {
        capacity[u][v] += cap;

        // Add both directions.
        // The reverse direction can be used later
        // to cancel previously sent flow.
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int maxFlow(int source, int sink) {
        int totalFlow = 0;

        while (true) {

            // Start a NEW path search.
            vector<bool> path(n, false);

            int pushed = dfs(
                source,
                sink,
                INT_MAX,
                path
            );

            // No more paths from source to sink.
            if (pushed == 0) {
                break;
            }

            totalFlow += pushed;
        }

        return totalFlow;
    }
};


int main() {
    // 0 = S
    // 1 = A
    // 2 = B
    // 3 = T

    FordFulkerson graph(4);

    graph.addEdge(0, 1, 3);  // S -> A = 3
    graph.addEdge(0, 2, 2);  // S -> B = 2
    graph.addEdge(1, 2, 3);  // A -> B = 3
    graph.addEdge(1, 3, 2);  // A -> T = 2
    graph.addEdge(2, 3, 3);  // B -> T = 3

    cout << "Max flow = "
         << graph.maxFlow(0, 3)
         << endl;

    return 0;
}
