// Given a graph, Design an algorithm and implement it using a program to implement Floyd-
// Warshall all pair shortest path algorithm.

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,e;
    cout<<"Enter the number of vertices and edges: ";
    cin>>n>>e;

    vector<vector<int>> dis(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)
                dis[i][j]=0;
            else
                dis[i][j]=INT_MAX;
        }
    }

    for(int i=0;i<e;i++){
        int u,v,w;
        cin>>u>>v>>w;

        dis[u][v]=w;
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dis[i][k]!=INT_MAX && dis[k][j]!=INT_MAX)
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    cout<<"Minimum Distances"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }
}