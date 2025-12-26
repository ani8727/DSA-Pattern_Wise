#include<iostream>
#include<list>
#include<vector>
#include<queue>
using namespace std;

// bfs for undirected enweighted graph

class Graph{
    public:
    int V;
    list<int> *adj;
    Graph(int v){
        V=v;
        adj=new list<int> [V];
    }
    void addEdge(int u, int v){
        if(u < 0 || u >= V || v < 0 || v  >= V) {
            cout << "Invalid edge: " << u << " " << v << endl;
            return;
        }
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
};

vector<int> bfs(Graph& g){
    vector<int> ans;
    vector<bool> visit(g.V, 0);
    queue<int> q;

    int node=0;
    q.push(node);
    visit[node]=1;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        ans.push_back(node);

        for(int neighbor: g.adj[node]){
            if(!visit[neighbor]){
                visit[neighbor]=1;
                q.push(neighbor);
            }
        }
    }
    return ans;

}

void traverse(Graph& g){
    for(int i=0;i<g.V;i++){
        cout<<i<<" : ";
        for(int neigh: g.adj[i]){
            cout<<neigh<<" ";
        }cout<<endl;
    }cout<<endl;
}

int main(){
    int n, e;
    cin>>n>>e;

    Graph g(n);
    for(int i=0;i<e;i++){
        int u, v;
        cin>>u>>v;
        g.addEdge(u, v);
    }

    cout<<"Print all adjency of graph"<<endl;
    traverse(g);

    vector<int> ans=bfs(g);
    cout<<"BFS traversal"<<endl;
    for(int i: ans){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}