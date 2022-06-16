// II.Given a directed graph, write an algorithm and a program to find mother vertex in a graph. A
// mother vertex is a vertex v such that there exists a path from v to all other vertices of the graph.

#include<bits/stdc++.h>
using namespace std;

int Find(int a,int par[]){
    if(par[a]==a){
        return a;
    }
    return Find(par[a],par);
}
void Union(int a,int b,int par[]){
    int p1=Find(a,par);
    int p2=Find(b,par);

    par[p2]=p1;
}
int main(){
    int v,e;
    cout<<"Enter the vertex and edges: ";
    cin>>v>>e;

    vector<pair<int,int>> adj;
    cout<<"Enter the edges"<<endl;
    for(int i=0;i<e;i++){
        int u1,v1;
        cin>>u1>>v1;

        adj.push_back({u1,v1});
    }

    int par[v];
    for(int i=0;i<v;i++){
        par[i]=i;
    }

    for(int i=0;i<e;i++){
        Union(adj[i].first,adj[i].second,par);
    }

    int ans=par[0];
    for(int i=0;i<v-1;i++){
        if(par[i]!=par[i+1]){
            cout<<"No mother vertex"<<endl;
            return 0;
        }
    }
    cout<<"Mother vertex found: "<<ans<<endl;
}