// Given an array of elements. Assume arr[i] represents the size of file i. Write an algorithm and a
// program to merge all these files into single file with minimum computation. For given two files
// A and B with sizes m and n, computation cost of merging them is O(m+n). (Hint: use greedy
// approach)

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    vector<int> ar(n,0);
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }

    sort(ar.begin(),ar.end());
    int sum=0;
    int curr_sum=ar[0];

    for(int i=1;i<n;i++){
        curr_sum+=ar[i];
        sum+=curr_sum;
        // cout<<sum<<" "<<curr_sum<<endl;
    }

    cout<<sum<<endl;
}