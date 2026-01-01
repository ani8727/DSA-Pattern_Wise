// Find Path Exisit in Graph - 1971

#include<iostream>
#include<vector>
#include<queue>
#include<list>

using namespace std;

class Graph{
    public:
    int V;
    list<int> *adj;
    Graph(int n){
        V=n;
        adj=new list<int> [V];
    }
    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
};

bool pathExist(Graph& g, int source, int destination){
    if(source==destination)
        return true;
    
    vector<bool> visit(g.V,false);

    queue<int> q;
    q.push(source);

    while(!q.empty()){
        int node=q.front();
        q.pop();

        if(source==destination)
            return true;
        
        for(int neighbor: g.adj[node]){
            if(!visit[node]){
                q.push(neighbor);
                visit[neighbor]=true;
            }
        }
    }
    return false;
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

    cout<<"Source and detination: ";
    int source, destination;
    cin>>source>>destination;

    if(pathExist(g,source,destination))
        cout<<"path Exist"<<endl;
    else    
        cout<<"path not exist"<<endl;

}