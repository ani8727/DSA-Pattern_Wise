// 11. Container With Most Water

#include<iostream>
#include<vector>
using namespace std;

// int calArea(vector<int>& heights){
//     int n=heights.size();
//     int maxArea=0;
//     for(int i=0;i<n-1;i++){
//         for(int j=i+1;j<n;j++){
//             int height=min(heights[i],heights[j]);
//             int width=j-i;
//             int area=height*width;
//             maxArea=max(maxArea,area);
//             cout<<height<<" "<<width<<" "<<area<<" "<<maxArea<<endl;;
//         }
//     }
//     return maxArea;
// }

// two pointer appraoch - opposite direction
int calArea(vector<int>& heights){
    int n=heights.size();
    int maxArea=0;
    int left=0, right=n-1;
    while(left<right){
        int height=min(heights[left],heights[right]);
        int width=right-left;
        int area=height*width;
        maxArea=max(maxArea,area);
        cout<<height<<" "<<width<<" "<<area<<" "<<maxArea<<endl;;
        // which pointer we have to move
        if(heights[left]<heights[right])  // whose value small them move - because we need large value
            left++;
        else
            right--;
    }
    return maxArea;
}

int main(){
    int n;
    cin>>n;
    vector<int> heights(n);

    for(int i=0;i<n;i++){
        cin>>heights[i];
    }

    int maxArea=calArea(heights);

    cout<<"max Water Conatins: "<<maxArea<<endl;

    return 0;
}