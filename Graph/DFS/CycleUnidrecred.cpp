//  Pattern DFS: 1.2A - Cycle Exist
// Cycle detection in Undirecte graph

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
        adj=new list<int> [v];
    }
    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
};

bool dfs(int node, int parent, Graph& g, vector<bool>& visit){
    visit[node]=true;

    for(int neighbor: g.adj[node]){
        if(!visit[neighbor]){
            if(dfs(neighbor,node,g,visit))
                return true;
        }
        else if(neighbor != parent){
            return true;
        }
    }
    return false;
}

bool isCycle(Graph& g){
    vector<bool> visit(g.v, false);

    for(int i=0;i<g.v;i++){
        if(!visit[i])
            if(dfs(i, -1, g, visit))
                return true;
    }
    return false;
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

    cout<<"Check Cycle detection: "<<endl;
    if(isCycle(g))
        cout<<"Cycle Present"<<endl;
    else
        cout<<"Cycle not Present"<<endl;
    
    return 0;
}