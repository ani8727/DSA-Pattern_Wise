// 
// 

#include<iostream>
#include<list>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

class Graph{
    public:
    int v;
    list<pair<int,int>> *adj;
    Graph(int n){
        v=n;
        adj=new list<pair<int,int>> [v];
    }
    void addEdge(int u, int v, int w){
        adj[u].push_back({v,w});
    }
};

vector<int> dijkstra(Graph& g, int src){
    vector<int> dist(g.v,INT_MAX);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[src]=0;
    pq.push({dist[src],src});

    while(!pq.empty()){
        auto p=pq.top();
        int d=p.first;
        int u=p.second;
        pq.pop();

        if(d>dist[u])
            continue;
        
        for( auto p2: g.adj[u]){
            int v=p2.first;
            int w=p2.second;
            if(dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
                pq.push({dist[v],v});
            }
        }
    }
    return dist;
}

int main(){
    int vertex, edges;
    cin>>vertex>>edges;

    Graph g(vertex);

    for(int i=0;i<edges;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g.addEdge(u,v,w);
    }

    int src=0;

    vector<int> shortDist=dijkstra(g,src);

    for(int i: shortDist){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}