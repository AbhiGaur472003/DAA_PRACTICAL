// Q-16 - Given a (directed/undirected) graph, design an algorithm and implement it using a program to find if a path exists between 
// two given vertices or not. (Hint: use DFS)

#include<bits/stdc++.h>
using namespace std;

bool FindPathDFS(vector<int> adj[],int s,int d,vector<bool>& visited){
    visited[s]=true;

    for(auto it: adj[s]){
        if(it==d){
            return true;
        }
        if(!visited[it]){
            if(FindPathDFS(adj,it,d,visited)){
                return true;
            }
        }
    }

    return false;
}
// For Undirected graph
void AddList(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
// For Directed graph
// void AddList(vector<int> adj[],int u,int v){
//     adj[u].push_back(v);
// }
int main(){
    int v,e;
    cout<<"Enter the number of vetices and edges:: ";
    cin>>v>>e;
    vector<int> adj[v];
    cout<<"Enter the edges::"<<endl;
    for(int i=0;i<e;i++){
        int u1,v1;
        cin>>u1>>v1;
        AddList(adj,u1,v1);
    }

    cout<<"Enter the vertices to find path:: ";
    int source,destination;
    cin>>source>>destination;

    vector<bool> visited(v,false);
    if(FindPathDFS(adj,source,destination,visited)){
        cout<<"Yes path exit"<<endl;
    }
    else{
        cout<<"No path exit"<<endl;
    }
}