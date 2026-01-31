// PATTERN 1: Frequency/Count MappingPattern 

// RecognitionKeywords: "count", "frequency", "how many times", "occurrences"Goal: 

// Track how often each element appearsTime: O(n), Space: O(k) where k = unique elements

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr;
    unordered_map<int,int> freq;
    for(int num : arr){ 
        freq[num]++;
    }

// With character counting

    string str;
    unordered_map<char,int> charCount;
    for(char c : str){
        charCount[c]++;
    }

// Find elements with specific frequency
    
    // for(auto&[element, count]: freq){
    //     if(count == k){// Process element
    //     }
    // }
    // return 0;
}

//                  Problem Set1
/* 
1. First Unique Character in String
2. Find first non-repeating character.
3. Valid Anagram - Check if two strings have same character frequencies.
4. Top K Frequent Elements - Return k most frequent elements.
4. Sort Characters by Frequency - Sort string by character frequency
5. Find All Anagrams in String - Find all anagram substrings
6. Custom Sort String - Sort based on custom character order
7. Unique Number of Occurrences - Check if all frequencies are unique
8. Uncommon Words from Two Sentences - Find words appearing once total
9. K Most Frequent Words - Return k most common words
10. Subdomain Visit Count - Aggregate domain visit countsInterview

*/


// Tips
/*
1. Start with: Creating frequency map, then query it
2. Optimization: Use array instead of map for limited character set (26 lowercase letters)
3. Follow-up: "Can you do it in one pass?" - Yes, build map while checking condition
4. Variant: Asked to find elements appearing exactly/at least/at most k times
*/