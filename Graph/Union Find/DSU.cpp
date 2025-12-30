#include<bits/stdc++.h>
using namespace std;

class UnionFind{
    public:
    vector<int> parent, rank;
    int components;
    UnionFind(int n){
        parent.resize(n);
        rank.resize(n,0);
        components=n;
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int find(int x){
        // path compress
        if(parent[x]!=x)
            parent[x]=find(parent[x]);
        return parent[x];
    }

    bool unionSet(int x, int y){
        int rootX=find(x);
        int rootY=find(y);

        if(rootX==rootY)
            return false;
        
        // union by rank
        if(rank[rootX]<rank[rootY]){
            parent[rootX]=rootY;
        }
        else if(rank[rootX]>rank[rootY]){
            parent[rootY]=rootX;
        }else{ // both rank same
            parent[rootY]=rootX;
            rank[rootX]++;
        }
        components--;
        return true;
    }

    bool connected(int x, int y){
        return find(x)==find(y);
    }
    int getComponents(){
        return components;
    }
};
