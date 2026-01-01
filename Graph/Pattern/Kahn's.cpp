// Topological sort - it shuld be DAG
// first appraoch - Kahn's-BFS algo

#include<iostream>
#include<vector>
#include<queue>
#include<list>

using namespace std;

class Graph{
    public:
    int v;
    list<int> *adj;
    Graph(int n){
        v=n;
        adj=new list<int> [v];
    }
    void addEdge(int u, int v){
        adj[u].push_back(v);
    }
};

vector<int> topoSort(Graph& g){
    // find indegree
    vector<int> indegree(g.v,0);

    for(int u=0;u<g.v;u++){
        for(int v: g.adj[u]){
            indegree[v]++;
        }
    }

    queue<int> q;
    for(int i=0;i<g.v;i++){
        if(indegree[i]==0)
            q.push(i);
    }
    vector<int> topo;

    while(!q.empty()){
        int node=q.front();
        q.pop();
        topo.push_back(node);

        for(int neighbor: g.adj[node]){
            indegree[neighbor]--;
            if(indegree[neighbor]==0){
                q.push(neighbor);
            }
        }
    }
    if(topo.size()!=g.v)
        return {};
    return topo;
}

int main(){
    int vertex, edges;
    cin>>vertex>>edges;

    Graph g(vertex);

    for(int i=0;i<edges;i++){
        int u, v;
        cin>>u>>v;
        g.addEdge(u,v);
    }

    vector<int>sort= topoSort(g);

    cout<<"Topo Sort - Kahn's algo"<<endl;
    for(int i: sort){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}