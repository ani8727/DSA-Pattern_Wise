// All Paths from Source to target - 797
// Back Tracking - dfs

#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph{
    public:
    int V;
    list<int> *adj;
    Graph(int n){
        V=n;
        adj=new list<int> [V];
    }
    void addEdge(int u, int v){
        // Graph is DAG
        adj[u].push_back(v);
    }
};

vector<vector<int>> ans;

void dfs(int node, Graph& g, vector<int>& path){
    path.push_back(node);

    if(node==g.V-1){
        ans.push_back(path);
    }else{
        for(int neighbor: g.adj[node]){
            dfs(neighbor,g,path);
        }
    }
    path.pop_back();
}

vector<vector<int>> allPath(Graph& g){
    vector<int>path;
    dfs(0,g,path);
    return ans;
}

int main(){
    int vertex, edges;
    cin>>vertex>>edges;

    Graph g(vertex);

    for(int i=0;i<edges;i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v);
    }

    //  all Paths of Graph
    vector<vector<int>> allPaths=allPath(g);

    for(vector<int> path: allPaths){
        for(int i:path){
            cout<<i<<" ";
        }cout<<endl;
    }

    return 0;
}