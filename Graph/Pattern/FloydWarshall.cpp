// 
// 
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Graph {
public:
    int V;
    vector<vector<int>> dist;

    Graph(int v) {
        V = v;
        dist.assign(V, vector<int>(V, INT_MAX));

        for (int i = 0; i < V; i++)
            dist[i][i] = 0;
    }

    void addEdge(int u, int v, int w) {
        dist[u][v] = min(dist[u][v], w);
    }
};

void floydWarshall(Graph& g) {
    // for all node one by one 
    for(int node=0;node<g.V;node++){

        // relaxation each index if possible
        for(int i=0;i<g.V;i++){
            for (int j=0;j<g.V;j++){

                if (g.dist[i][node]!=INT_MAX && g.dist[node][j]!=INT_MAX) {
                    g.dist[i][j] = min(
                        g.dist[i][j],g.dist[i][node]+g.dist[node][j]
                    );
                }
            }
        }
    }
}

bool hasNegativeCycle(Graph& g) {
    for (int i = 0; i < g.V; i++) {
        if (g.dist[i][i] < 0)
            return true;
    }
    return false;
}

int main() {
    int V, E;
    cin >> V >> E;

    Graph g(V);

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    floydWarshall(g);

    if (hasNegativeCycle(g)) {
        cout << "Negative Cycle Exist\n";
    } else {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (g.dist[i][j] == INT_MAX)
                    cout << "No Edge ";
                else
                    cout << g.dist[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
