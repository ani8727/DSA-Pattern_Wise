//  DFS Pappern : 1.2B -> cycle detection
// finde cycle dectrion in directed graph- using three color

#include<bits/stdc++.h>
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
    }
};

bool dfs(int node, Graph& g, vector<int>& visit){
    visit[node]=1;  // gray

    for(int neighbor: g.adj[node]){
        if(visit[neighbor]==0){
            if(dfs(neighbor,g,visit))
                return true;
        }
        else if(visit[neighbor]==1){
            return true;
        }
    }
    visit[node]=2; // black
    return false;
}

bool isCycle(Graph& g){
    vector<int> visit(g.v, 0); // white

    for(int i=0;i<g.v;i++){
        if(!visit[i])
            if(dfs(i,g,visit))
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
        g.addEdge(u, v);
    }

    cout<<"Detect Cycle in connected graph"<<endl;
    if(isCycle(g)){
        cout<<"Cycle Present"<<endl;
    }
    else{
        cout<<"Cycle not Present"<<endl;
    }

    return 0;

}
