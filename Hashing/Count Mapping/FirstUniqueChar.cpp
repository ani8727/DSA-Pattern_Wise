// 387. First Unique Character in a String

#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>

using namespace std;

int firstUnique(string s){
    unordered_map<char,int> freq;

    for(char ch: s){
        freq[ch]++;
    }

    // check map have
    for(int i=0;i<s.length();i++){
        if(freq[s[i]]==1){
            return i;
        }
    }
    return -1;
}
// using constant size 

int firstUnique2(string s){
    //only lower alphabets
    vector<int> freq(26,0);
    for(char ch: s){
        freq[ch-'a']++;
    }

    for(int i=0;i<s.length();i++){
        if(freq[s[i]-'a']==1)
            return i;
    }
    return -1;
}

// sinlge pass

int firstUniqe3(string s){
    unordered_map<char,int> freq;
    queue<int> q;

    for(int i=0;i<s.length();i++){
        if(freq.find(s[i])==freq.end()){ // its new index
            q.push(i);  // push idx of that char
        }
        // increase freq
        freq[s[i]]++;

        // check when first queue idx - is not uniyq so remove it
        while(q.size()>0 && freq[s[q.front()]]>1){ // remove it - not unique
            q.pop();  // front pop;
        }
    }
    return q.empty()? -1:q.front();
}

int main(){
    string s;
    cin>>s;
    
    cout<<firstUnique(s)<<endl;
    cout<<firstUnique2(s)<<endl;
    cout<<firstUniqe3(s)<<endl;

    return 0;
}