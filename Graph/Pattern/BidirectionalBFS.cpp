// Patterns: 2.3 - Bidirectional BFS 
// find shortest path length b/w two noed in unweighted graph

#include<bits/stdc++.h>
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
        adj[v].push_back(u);
    }
};

int minPath(Graph& g, int start, int end){
    if(start==end) return 0;
    
    // hme do set lena - back and front
    unordered_set<int> front, back;

    // hme do set - visited ko store karenge
    unordered_set<int> visitFront, visitBack;

    // start and end dol do - process karne ke liye
    front.insert(start);
    back.insert(end);

    // visited mark kar do
    visitFront.insert(start);
    visitBack.insert(end);

    int step=0;  // length store

    while(!front.empty() && !back.empty()){ // agar ek bhi empty ho jata hai exist nhi karta length 

        // pahle hamesh samll ko procees karo
        // front ko kro or condtion pe swap kar do
        if(front.size()>back.size()){
            swap(back,front);
            swap(visitBack,visitFront);
        }
        // nye ko store karo ispe process karne ke liye
        unordered_set<int> next;
        step++;  // insrease step

        for(int node: front){ // process each node of set
            for(int neighbor: g.adj[node]){  // traverse their neighbor
                // now check tow condition
                if(visitBack.count(neighbor)){ // agar opposite set mai vistt hogya
                    return step;
                }
                if(!visitFront.count(neighbor)){ // agar same visit nhi hai to
                    next.insert(neighbor);  // next ke liye store kro
                    visitFront.insert(neighbor); // mark kar do
                }
            }
        }
        front=next;  // next process ke liye store sare front mai dal do
    }
    return -1; // no path exist
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

    cout<<"Min Length path: "<<minPath(g,start,end)<<endl;

    return 0;
}