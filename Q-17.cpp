// Q-17 - Given a graph, design an algorithm and implement it using a program to find if a graph is bipartite or not. (Hint: use BFS)
// {0, 1}, {1, 2}, {1, 7}, {2, 3}, {3, 5}, {4, 6}, {4, 8}, {7, 8}      ---------->   OUTPUT (YES)

#include<bits/stdc++.h>
using namespace std;
bool CheckDFS(vector<int> adj[],int s,vector<int>& col){
    queue<int> q;
    q.push(s);
    col[s]=1;

    while(!q.empty()){
        int a=q.front();
        q.pop();
        for(auto it: adj[a]){
            if(col[it]==-1){
                col[it]=1-col[a];
                q.push(it);
            }
            else if(col[it]==col[a]){
                return false;
            }
        }
    }

    return true;
}
bool CHECKBIPARTILE(vector<int> adj[],int n){
    vector<int> col(n,-1);

    for(int i=0;i<n;i++){
        if(col[i]==-1){
            if(!CheckDFS(adj,i,col)){
                return false;
            }
        }
    }
}
void AddList(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
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

   if(CHECKBIPARTILE(adj,v)){
       cout<<"Yes"<<endl;
   }
   else{
       cout<<"No"<<endl;
   }
}


/*
8 7 
0 1 
1 2 
2 3 
3 4 
4 6 
6 7 
1 7
4 5 

// bipartite graph example 
*/ 

/*
7 7 
0 1 
1 2 
2 3 
3 4 
4 6 
6 1
4 5 
// not bipartite example
*/



