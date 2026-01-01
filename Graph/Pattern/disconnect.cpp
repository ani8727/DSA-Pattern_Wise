// DFS - when graph in disconnected
#include<iostream>
#include<list>
#include<vector>

using namespace std;

class Graph{
    public:
    int v;
    list<int>* adj;
    Graph(int n){
        v=n;
        adj=new list<int>[v];
    }
    void addEdge(int u, int v){
        adj[u].push_back(v);
    }
};

void dfsHelp(Graph& g, int node, vector<int>& ans, vector<bool>& visit){
    ans.push_back(node);
    visit[node]=true;

    for(int neighbor: g.adj[node]){
        if(!visit[neighbor]){
            dfsHelp(g, neighbor, ans, visit);
        }
    }
}

vector<int> dfs(Graph& g){
    vector<int> ans;
    vector<bool> visit(g.v, false);

    for(int i=0;i<g.v;i++){
        if(!visit[i]){
            dfsHelp(g, i, ans, visit);
        }
    }
    return ans;
}

int main(){
    int vertex, edges;
    cin>>vertex>>edges;

    Graph g(vertex);

    for(int i=0;i<edges;i++){
        int u, v;
        cin>>u>>v;
        g.addEdge(u, v);
    }

    vector<int> ans=dfs(g);

    for(int i: ans){
        cout<<i<<" ";
    }

    return 0;

}
