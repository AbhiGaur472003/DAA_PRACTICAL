// Q-18 -Given a directed graph, design an algorithm and implement it using a program to find whether cycle exists in the graph or not.









#include<bits/stdc++.h>
using namespace std;

bool FindCycle(vector<int> adj[],vector<int>& vis,vector<int>& dfsvis,int s){
    vis[s]=true;
    dfsvis[s]=true;

    for(auto x: adj[s]){
        if(!vis[x]){
            if(FindCycle(adj,vis,dfsvis,x)){
                return true;
            }
        }
        else if(dfsvis[x]){
            return true;
        }
    }
    dfsvis[s]=false;

    return  false;
}
bool DETECTCYCLE(vector<int> adj[],int v){
    vector<int> vis(v,false);
    vector<int> dfsvis(v,false);
    for(int i=0;i<v;i++){
        if(!vis[i]){
            if(FindCycle(adj,vis,dfsvis,i)){
                return true;
            }
        }
    }

    return false;
}
void AddList(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
}
int main(){
    int v,e;
    cout<<"Enter the number of vetices and edges:: ";
    cin>>v>>e;

    vector<int> adj[v];
    cout<<"Enter the edges::"<<endl;
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        AddList(adj,u,v);
    }

   if(DETECTCYCLE(adj,v)){
       cout<<"Yes Cycle Exist"<<endl;
   }
   else{
       cout<<"No Cycle Exist"<<endl;
   }
}