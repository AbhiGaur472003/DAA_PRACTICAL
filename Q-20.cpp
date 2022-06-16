// Design an algorithm and implement it using a program to solve previous question's problem using
// Bellman- Ford's shortest path algorithm.

#include<bits/stdc++.h>
using namespace std;

struct  node{
    int u,v,w;
    node(int uu,int vv,int ww){
        u=uu;
        v=vv;
        w=ww;
    }
};
int main(){
    int ve,e;
    cout<<"Enter the number of vetices and edges:: ";
    cin>>ve>>e;

    vector<node> adj;
    cout<<"Enter the edges and weight::"<<endl;
    for(int i=0;i<e;i++){
        int u,v,wt;
        cin>>u>>v>>wt;

        adj.push_back(node(u,v,wt));
    }
    int inf=1000000;
    vector<int> d(ve,inf);
    int s;
    cout<<"Enter the source: ";
    cin>>s;
    d[s]=0;
    for(int i=1;i<=ve-1;i++){
        for(auto it: adj){
            if(d[it.u]+it.w < d[it.v]){
                d[it.v]=d[it.u]+it.w;
            }
        }
    }

    for(auto it: adj){
        if(d[it.u]+it.w < d[it.v]){
            d[it.v]=d[it.u]+it.w;
            cout<<"Negative Cycle";
            return 0;
        }
    }
    cout<<"Distances"<<endl;
    for(int i=0;i<ve;i++){
        cout<<s<<" to "<<i<<" distance is: "<<d[i]<<endl;
    }

    return 0;
}















