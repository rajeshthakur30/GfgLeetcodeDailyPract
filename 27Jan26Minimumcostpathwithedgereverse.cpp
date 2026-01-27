#include <bits/stdc++.h>
using namespace std;

int minCost(int n, vector<vector<int>>& edges) {
    vector<vector<pair<int,int>>> adj(n);

    // Build graph
    for (auto &e : edges) {
        int u = e[0], v = e[1];
        adj[u].push_back({v, 0}); // original direction
        adj[v].push_back({u, 1}); // reversed direction
    }

    deque<int> dq;
    vector<int> dist(n, INT_MAX);

    dist[0] = 0;
    dq.push_front(0);

    while (!dq.empty()) {
        int node = dq.front();
        dq.pop_front();

        for (auto &it : adj[node]) {
            int next = it.first;
            int cost = it.second;

            if (dist[node] + cost < dist[next]) {
                dist[next] = dist[node] + cost;
                if (cost == 0)
                    dq.push_front(next);
                else
                    dq.push_back(next);
            }
        }
    }

    return dist[n - 1] == INT_MAX ? -1 : dist[n - 1];
}

int main() {
    int n = 5;
    vector<vector<int>> edges = {
        {0, 1},
        {2, 1},
        {2, 3},
        {3, 4}
    };

    cout << minCost(n, edges);
    return 0;
}
