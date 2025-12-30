#include <bits/stdc++.h>
using namespace std;

/*
    Graph using adjacency list
    adj[u] = {v, weight}
*/
class Graph {
public:
    int V;
    vector<vector<pair<int,int>>> adj;

    Graph(int n) {
        V = n;
        adj.resize(V);
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // undirected graph
    }
};

int primMST(Graph& g) {

    vector<bool> inMST(g.V, false);

    // min-heap: {weight, node}
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    int mstWeight = 0;
    int verticesUsed = 0;

    // start from node 0
    pq.push({0, 0});

    while (!pq.empty() && verticesUsed < g.V) {

        auto [weight, u] = pq.top();
        pq.pop();

        if (inMST[u]) continue;

        inMST[u] = true;
        mstWeight += weight;
        verticesUsed++;

        for (auto [v, w] : g.adj[u]) {
            if (!inMST[v]) {
                pq.push({w, v});
            }
        }
    }

    // If graph is disconnected
    if (verticesUsed != g.V)
        return -1;

    return mstWeight;
}

int main() {

    int vertex, edges;
    cin >> vertex >> edges;

    Graph g(vertex);

    for (int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    int result = primMST(g);

    if (result == -1)
        cout << "Graph is not connected, MST not possible\n";
    else
        cout << "MST Prim: " << result << endl;

    return 0;
}
