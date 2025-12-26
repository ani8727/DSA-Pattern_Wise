//  1. DFS Patterns -> Count Number province  connected in undirected graph
// this will not work for directed graph
#include<iostream>
#include<list>
#include<vector>
#include<stack>
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

int province(Graph& g){
    vector<bool> visit(g.v, false);
    int count=0;
    for(int i=0;i<g.v;i++){
        if(!visit[i]){
            stack<int> st;
            st.push(i);
            visit[i]=true;

            while(!st.empty()){
                int node=st.top();
                st.pop();
                for(int neighbor: g.adj[node]){
                    if(!visit[neighbor]){
                        st.push(neighbor);
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
        int u, v;
        cin>>u>>v;
        g.addEdge(u,v);
    }

    cout<<"Number of provice im Map : ";
    cout<<province(g)<<endl;

    return 0;

}