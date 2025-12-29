// 
// 
#include<iostream>
#include<vector>
#include<tuple>
#include<climits>
using namespace std;

class Graph{
    public:
    int V;
    vector<tuple<int,int,int>> adj;
    Graph(int v, int e){
        this->V=v;
    }
    void addEdge(int u, int v, int w){
        adj.push_back({u, v, w});
    }
};

vector<int> bellmonFord(Graph& g, int src){
    vector<int> dist(g.V,INT_MAX);
    dist[src]=0;

    // v-1 relaxation
    for(int i=1;i<=g.V-1;i++){
        bool update=false; //keep track if not update then its find shortest
        // all egdes reach to make relaxation one by one
        for(auto& edge: g.adj){
            int u,v,w;
            tie(u, v, w) = edge; // u -> v and w all assign
            
            // two condition
            if(dist[u]!=INT_MAX && dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
                update=true;
            }
        }
        // if update not true means already one at this step
        if(!update)
            break;
    }

    // check negative cycle exist - if exist meean wrong data
    for(auto& edge: g.adj){
        int u,v,w;
        tie(u,v,w)=edge;

        // if still need to improve then neagtive cycle exist
        if(dist[u]!=INT_MAX && dist[u]+w<dist[v]){
            return {};
        }
    }
    return dist;
}
int main(){
    int vertex, edges;
    cin>>vertex>>edges;

    Graph g(vertex,edges);

    for(int i=0;i<edges;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g.addEdge(u,v,w);
    }

    vector<int> shortDis=bellmonFord(g,0);

    if(!shortDis.empty()){
        for(int i: shortDis){
            cout<<i<<" ";
        }cout<<endl;
    }else{
        cout<<"Negative Cycle Exist"<<endl;
    }

    return 0;
}