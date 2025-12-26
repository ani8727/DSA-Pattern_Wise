// DFS - when graph in disconnected
// using explicit Stack 
#include<iostream>
#include<list>
#include<stack>
#include<vector>

using namespace std;

class Graph{
    public:
    int v;
    list<int>* adj;
    Graph(int n){
        v=n;
        adj=new list<int>[v];
    }
    void addEdge(int u, int v){
        adj[u].push_back(v);
    }
};

vector<int> dfs(Graph& g){
    vector<int> ans;
    vector<bool> visit(g.v, false);
    stack<int> st;

    for(int i=0;i<g.v;i++){
        if(!visit[i]){
            st.push(i);
            visit[i]=true;

            while(!st.empty()){
                int node=st.top();
                st.pop();
                ans.push_back(node);
                for(int neighbor: g.adj[node]){
                    if(!visit[neighbor]){
                        visit[neighbor]=true;
                        st.push(neighbor);
                    }
                }
            }
        }
    }
    return ans;
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

    vector<int> ans=dfs(g);

    for(int i: ans){
        cout<<i<<" ";
    }

    return 0;

}
