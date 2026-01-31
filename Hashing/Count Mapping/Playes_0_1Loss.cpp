// 2225. Find Players With Zero or One Losses

#include<iostream>
#include<vector>
#include<map>
using namespace std;

vector<vector<int>> findWinners(vector<vector<int>>& matches){

    vector<vector<int>> winners;
    // tow order map to store lost and won player
    map<int,int> won;
    map<int,int> lost;

    for(vector<int> &match: matches){
        won[match[0]]++;
        lost[match[1]]++;
    }

    vector<int> winner1;
    vector<int> winner2;

    // no lost match
    for(auto &play: won){
        int player=play.first;
        // this playes not inside lost match
        if(lost.find(player)==lost.end()){
            winner1.push_back(player);
        }
    }

    // one lost match
    for(auto &play: lost){
        int player=play.first;
        if(lost[player]==1){
            winner2.push_back(player);
        }
    }

    winners.push_back(winner1);
    winners.push_back(winner2);

    return winners;
}

int main(){
    int n;
    cin>>n;

    vector<vector<int>> matches(n,vector<int>(2));

    for(int i=0;i<n;i++){
        cin>>matches[i][0];
        cin>>matches[i][1];
    }

    vector<vector<int>> winners=findWinners(matches);

    for(vector<int> winner: winners){
        cout<<"Winner :";
        for(int i: winner){
            cout<<i<<" ";
        }cout<<endl;
    }cout<<endl;

    return 0;
}