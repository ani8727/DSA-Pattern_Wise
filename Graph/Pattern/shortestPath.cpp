// Shortest Path Unweighted graph
// level based Distanece Tracking (Canonical Approach)
// it works for  unweighted -> directed, directed and cycle all

#include<bits/stdc++.h>
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
        adj[v].push_back(u);
    }
};

int shortPath(Graph& g, int start, int end){
    if(start==end) return 0;
    vector<bool> visit(g.v, false);
    queue<int> q;

    visit[start]=true;
    q.push(start);

    int dist=0;

    while(!q.empty()){
        int levelSize=q.size();
        dist++;

        for(int i=0;i<levelSize;i++){
            int node=q.front();
            q.pop();

            for(int neighbor: g.adj[node]){
                if(neighbor == end) return dist;

                if(!visit[neighbor]){
                    visit[neighbor]=true;
                    q.push(neighbor);
                }
            }
        }
    }
    return -1;
}


int main(){
    int edges, vertex;
    cin>>vertex>>edges;

    Graph g(vertex);

    for(int i=0;i<edges;i++){
        int u, v;
        cin>>u>>v;
        g.addEdge(u,v);
    }

    int start, end;
    cin>>start>>end;

    cout<<"Shortest Path: "<<shortPath(g, start, end)<<endl;

    return 0;
}