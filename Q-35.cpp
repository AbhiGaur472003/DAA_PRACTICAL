// II. Given a knapsack of maximum capacity w. N items are provided, each having its own value and
// weight. Design an algorithm and implement it using a program to find the list of the selected items
// such that the final selected content has weight <= w and has maximum value. Here, you cannot
// break an item i.e. either pick the complete item or don't pick it. (0-1 property).

#include<bits/stdc++.h>
using namespace std;


int KNAPSACK(int n,vector<int>& val,vector<int>& wt,int w){
    int dp[n+1][w+1];

    for(int i=0;i<n+1;i++){
        for(int j=0;j<w+1;j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }
        }
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            if(wt[i-1]<=j){
                dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    for(int i=0;i<n+1;i++){
        for(int j=0;j<w+1;j++){
            cout<<dp[i][j]<<"\t ";
        }
        cout<<endl;
    }
    return dp[n][w];
}
int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    vector<int> wt(n);
    vector<int> val(n);
    cout<<"Enter the weight: ";
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }
    cout<<"Enter the value: ";
    for(int i=0;i<n;i++){
        cin>>val[i];
    }

    int w;
    cin>>w;

    cout<<KNAPSACK(n,val,wt,w);

}