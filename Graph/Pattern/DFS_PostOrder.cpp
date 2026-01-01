// TopoSort - Using DFS and post order

#include<iostream>
#include<list>
#include<vector>
#include<stack>
using namespace std;

class Graph{
    public:
    int v;
    vector<vector<int>> adj;
    Graph(int v){
        this->v=v;
        adj.resize(v);
    }
    void addEdge(int u, int v){
        adj[u].push_back(v);
    }
};

void dfs(Graph& g, int node, vector<bool>& visit, stack<int>& st){
    visit[node]=true;

    for(int neighbor: g.adj[node]){
        if(!visit[neighbor]){
            dfs(g,neighbor,visit,st);
        }
    }
    st.push(node);
}

vector<int> topoSort(Graph& g){
    vector<bool> visit(g.v, false);
    stack<int> st;

    for(int i=0;i<g.v;i++){
        if(!visit[i]){
            dfs(g,i,visit,st);
        }
    }

    vector<int> sort;
    while(!st.empty()){
        sort.push_back(st.top());
        st.pop();
    }

    return sort;
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

    vector<int> sort=topoSort(g);

    for(int i: sort){
        cout<<i<<" ";
    }
    return 0;
}