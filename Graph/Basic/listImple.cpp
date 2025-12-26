//  Implementation using inbuilt list
#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph{
    int V;
    list<pair<int,int>> *l; // int *arr

public:
    Graph(int V){
        this->V=V;
        l=new list<pair<int,int>> [V];
    }

    void addEdge(int u, int v, int w){
        l[u].push_back({v, w});
        l[v].push_back({u, w});
    }

    void print(){
        for(int i=0;i<V;i++){
            cout<<i<<" : ";
            for(pair<int, int> neighbor: l[i]){
                cout<<neighbor.first<<","<<neighbor.second<<" ";
            }cout<<endl;
        }
    }
};

int main(){
    int v, e;
    cin>>v>>e;

    Graph g(v);

    for(int i=0;i<e;i++){
        int u, v, w;
        cin>>u>>v>>w;
        g.addEdge(u,v,w);
    }

    cout<<"Print Graph"<<endl;
    g.print();

    return 0;
}