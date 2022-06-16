// Given a knapsack of maximum capacity w. N items are provided, each having its own value and
// weight. You have to Design an algorithm and implement it using a program to find the list of the
// selected items such that the final selected content has weight w and has maximum value. You can
// take fractions of items,i.e. the items can be broken into smaller pieces so that you have to carry
// only a fraction xi of item i, where 0 ≤xi≤ 1.

#include<bits/stdc++.h>
using namespace std;

bool cmp(const pair<int,int>& p1,const pair<int,int>& p2){
    return (double)((double)p1.first/(double)p1.second) > (double)((double)p2.first/(double)p2.second);
}
double FindFractional(int n,vector<pair<int,int>>& ar,int w){
    sort(ar.begin(),ar.end(),cmp);
    int curr_wt=0;
    double f=0.0;
    for(int i=0;i<n;i++){
        if(curr_wt + ar[i].second <= w){
            curr_wt+=ar[i].second;
            f+=ar[i].first;
        }
        else{
            int r=w-curr_wt;
            f+=((double)ar[i].first/(double)ar[i].second) * (double)r;
            break;
        }
    }

    return f;
}
int main(){
    int n;
    cout<<"Enter the size of array:: ";
    cin>>n;

    vector<pair<int,int>> ar;

    cout<<"Enter the value and weight:: ";
    for(int i=0;i<n;i++){
        int v,w;
        cin>>v>>w;
        ar.push_back({v,w});
    }

    int wt;
    cout<<"Enter the weight of knapsack:: ";
    cin>>wt;
   
    cout<<FindFractional(n,ar,wt)<<endl;
}