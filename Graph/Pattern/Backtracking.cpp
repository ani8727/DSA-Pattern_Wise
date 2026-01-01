// Pattern DFS: 1.3 -> Backtracking
// explore all path by -> mark - process - unmark
#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
    int v;
    list<int> *adj;
    Graph(int n){
        v=n;
        adj=new list<int>[v];
    }
    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
};

void backtracking(int node, Graph& g, vector<bool>& visit, vector<int>& path ){
    visit[node]=true;
    path.push_back(node);

    // print current path vector
    for(int i: path){
        cout<<i<<" ";
    }cout<<endl;

    for(int neighbor: g.adj[node]){
        if(!visit[neighbor]){
            backtracking(neighbor, g, visit, path);
        }
    }
    // back track
    visit[node]=false;
    path.pop_back();
}

void allPath(Graph g){
    vector<bool> visit(g.v, false);
    vector<int> path;

    for(int i=0;i<g.v;i++){
        if(!visit[i]){
            backtracking(i,g,visit,path);
        }
    }
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

    allPath(g);

    return 0;

}