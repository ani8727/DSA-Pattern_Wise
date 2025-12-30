//  1. Number of Provice - 547
#include<iostream>
#include<vector>
#include<list>
#include<queue>
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

int numProvince(Graph& g){
    // bfs cal
    int count=0;
    vector<bool> visit(g.v,false);

    for(int i=0;i<g.v;i++){
        if(!visit[i]){
            queue<int> q;
            q.push(i);
            visit[i]=true;

            while(!q.empty()){
                int node=q.front();
                q.pop();

                for(int neighbor: g.adj[node]){
                    if(!visit[neighbor]){
                        q.push(neighbor);
                        visit[neighbor]=true;
                    }
                }
            }
            count++;
        }
    }
    return count;
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

    cout<<"Number of Provice: "<<numProvince(g)<<endl;

    return 0;
}
