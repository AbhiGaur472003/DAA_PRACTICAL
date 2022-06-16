// III. Given a set of elements, you have to partition the set into two subsets such that the sum of elements
// in both subsets is same. Design an algorithm and implement it using a program to solve this
// problem.

#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> v,int sum){
    int n=v.size();
    bool t[n+1][sum+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(j==0){
                t[i][j]=true;
            }
            if(i==0){
                t[i][j]=false;
            }
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(v[i-1]<=j){
                t[i][j]=(t[i-1][j] || t[i-1][j-v[i-1]]);
                //cout<<t[i][j]<<" ";
            }
            else{
                t[i][j]=t[i-1][j];
                //cout<<t[i][j]<<" ";
            }
        }
    }
    return t[n][sum];
}
int main(){
    int n;
    cout<<"Enter the size of array:: ";
    cin>>n;

    int sum=0;
    vector<int> v(n);
    cout<<"Enter the elements:: ";
    for(int i=0;i<n;i++){
        cin>>v[i];
        sum+=v[i];
    }
    if(sum%2!=0){
        cout<<"No"<<endl;
    }
    else {
        sum/=2;
        if(check(v,sum)){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }

}