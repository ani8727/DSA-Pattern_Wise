#include<iostream>
#include<list>
#include<vector>
using namespace std;

// dfs for directed and wighted graph
class Graph{
    public:
    int v;
    list<pair<int,int>> *adj;
    Graph(int n){
        v=n;
        adj=new list<pair<int, int>> [v];
    }
    void addEdge(int u, int v, int w){
        adj[u].push_back({v, w});
    }
};

void recursion(Graph& g, int node, vector<int>& ans, vector<bool>& visit){
    ans.push_back(node);
    visit[node]=true;

    for(pair<int, int> p: g.adj[node]){
        int neighbor=p.first;
        if(!visit[neighbor]){
            recursion(g, neighbor, ans, visit);
        }
    }
}

vector<int> dfs(Graph& g){
    
    vector<bool> visit(g.v, false);
    
    vector<int> ans;
    int node=0;
    recursion(g, 0, ans, visit);

    return ans;
}

int main(){
    int node, edge;
    cin>>node>>edge;

    Graph g(node);

    for(int i=0;i<edge;i++){
        int u, v, w;
        cin>>u>>v>>w;
        g.addEdge(u,v,w);
    }

    vector<int> ans=dfs(g);

    for(int i: ans){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}