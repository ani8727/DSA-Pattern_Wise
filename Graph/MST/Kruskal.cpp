// Kruskal Algorithm

#include<iostream>
#include<vector>
#include<list>
#include<tuple>
#include<algorithm>

using namespace std;

class Graph{
    public:
    int V;
    vector<tuple<int,int,int>> adj;
    Graph(int n){
        V=n;
    }
    void addEdge(int u, int  v, int w){
        adj.push_back({w,u,v});
    }
};

class DSU{
    public:
    int components;
    vector<int> rank, parent;
    DSU(int n){
        components=n;
        rank.resize(components,0);
        parent.resize(components);

        for(int i=0;i<components;i++){
            parent[i]=i;
        }
    }

    int find(int x){
        if(parent[x]!=x){
            parent[x]=find(parent[x]);
        }
        return parent[x];
    }
    bool unionSets(int x, int y){
        int rootX=find(x);
        int rootY=find(y);

        if(rootX==rootY) return false;

        if(rank[rootX]<rank[rootY])
            parent[rootX]=rootY;
        else if(rank[rootX]>rank[rootY])
            parent[rootY]=rootX;
        else{
            parent[rootY]=rootX;
            rank[rootX]++;   
        }
        return true;
    }    
};

int kruskalMST(Graph& g){
    // sort edges by weights
    sort(g.adj.begin(),g.adj.end());

    DSU uf(g.V);

    // count store
    int mstWeight=0;
    int edgeUsed=0;

    for(auto t: g.adj){
        int w,u,v;
        tie(w,u,v)=t;

        // set in DSU;
        if(uf.unionSets(u,v)){// ture aayega to paernt same nhi tha mtb use nhi hua tha
            mstWeight+=w;
            edgeUsed++;
            if(edgeUsed==g.V-1) 
                break;
        }
    }
    return (edgeUsed==g.V-1)? mstWeight:-1;
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

    // Minimum Spanning tree- Kruskal Algo
    cout<<"MST Kruskal: "<<kruskalMST(g)<<endl;

    return 0;
}
