// 509. Fibonacci Number

#include<iostream>
#include<vector>
using namespace std;

// optimal DP- store onlt needed var
int fib(int n){
    if(n<=1)
        return n;
    int prev2=0;
    int prev1=1;

    int curr;

    for(int i=2;i<=n;i++){
        curr=prev1+prev2;
        prev2=prev1;
        prev1=curr;
    }
    return curr;
}


// DP - bottom up approach- tabulization or iterative
int fib(int n){
    // basic condtion - not necassary but optimal
    if(n<=1)
        return n;
    // create table 
    vector<int> dp(n+1,-1);

    // store basic state
    dp[0]=0;
    dp[1]=1;

    // itreate to store val at nth index
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

/*
// DP - top Down appraoch - recursion cashe
int fibDP(int n, vector<int>& dp){
    // base condition
    if(n<=1)
        return n;
    // if already cal, and store
    if(dp[n]!=-1)
        return dp[n];  // then return those nth number
    // if not then call recurstion adn store return val
    return dp[n]=fibDP(n-1,dp)+fibDP(n-2,dp);
}
int fib(int n){
    // memo table for store
    vector<int> dp(n+1, -1);
    // call function
    return fibDP(n,dp);
}
*/

/*
// simple recursive
int fib(int n){
    if(n <=1)
        return n;
    return fib(n-1)+fib(n-2);
}
*/


int main(){
    int n;
    cin>>n;

    cout<<"nth Number: "<<fib(n)<<endl;

    return 0;
}