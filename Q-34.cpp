// I. Given two sequences, Design an algorithm and implement it using a program to find the length
// of longest subsequence present in both of them. A subsequence is a sequence that appears in the
// same relative order, but not necessarily contiguous.


#include<bits/stdc++.h>
using namespace std;

string LCS(string s1,string s2,int n,int m){
    int dp[n+1][m+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
        }
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    int i=n,j=m;
    string s;

    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            s.push_back(s1[i-1]);
            i--;
            j--;
        }
        else{
            if(dp[i][j-1] > dp[i-1][j]){
                j--;
            }
            else{
                i--;
            }
        }
    }

    reverse(s.begin(),s.end());
    return s;
}
int main(){
    string s1;
    cout<<"Enter first sequence : ";
    cin>>s1;

    string s2;
    cout<<"Enter second sequence : ";
    cin>>s2;

    string s=LCS(s1,s2,s1.size(),s2.size());
    cout<<"Longest Common Subsequence: "<<s<<endl<<"Length: "<<s.length()<<endl;

}