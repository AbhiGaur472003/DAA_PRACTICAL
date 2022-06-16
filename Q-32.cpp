// II. Given a set of available types of coins. Let suppose you have infinite supply of each type of coin.
// For a given value N, you have to Design an algorithm and implement it using a program to find
// number of ways in which these coins can be added to make sum value equals to N.

#include<bits/stdc++.h>
using namespace std;

void FIND(vector<int>& v,int& sum,int& count,int i){
    if(sum==0){
        count++;
        return ;
    }
    if(i==v.size()){
        if(sum==0){
            count++;
        }
        return ;
    }
    if(sum<0){
        return ;
    }

    sum-=v[i];
    FIND(v,sum,count,i);

    sum+=v[i];
    FIND(v,sum,count,i+1);
}
int main(){
    int n;
    cin>>n;

    vector<int> v(n,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    int sum=0;
    cin>>sum;

    int count=0;
    FIND(v,sum,count,0);
    cout<<count<<endl;
}