// Assume that a project of road construction to connect some cities is given to your friend. Map of
// these cities and roads which will connect them (after construction) is provided to him in the form
// of a graph. Certain amount of rupees is associated with construction of each road. Your friend has
// to calculate the minimum budget required for this project. The budget should be designed in such
// a way that the cost of connecting the cities should be minimum and number of roads required to
// connect all the cities should be minimum (if there are N cities then only N-1 roads need to be
// constructed). He asks you for help. Now, you have to help your friend by designing analgorithm
// which will find minimum cost required to connect these cities. (use Prim's algorithm)

#include<bits/stdc++.h>
using namespace std;

int FindMinimumEdgeWeight(vector<int> W,vector<bool> mst){
    int mn=INT_MAX;
    int u;
    for(int i=0;i<W.size();i++){
        if(W[i]<mn && mst[i]==false){
            mn=W[i];
            u=i;
        }
    }

    return u;
}
bool Complete( vector<bool> mst){
    for(auto it : mst){
        if(it==false){
            return true;
        }
    }

    return false;
}
void PrismAlgo(vector<pair<int,int>> adj[],int n){
    vector<int> W(n,INT_MAX);
    vector<bool> mst(n,false);
    vector<int> p(n,-1);

    W[0]=0;
    int sum=0;
    for(int i=0;i<n-1;i++){
        int a=FindMinimumEdgeWeight(W,mst);
        mst[a]=true;

        for(auto it: adj[a]){
            if(it.second < W[it.first]){
                W[it.first]=it.second;
                p[it.first]=a;
                // sum+=it.second;
            }
        }
    }
    for(int i=0;i<n;i++){
        sum+=W[i];
    }
    cout<<"Minimum Weight: "<<sum<<endl;
}
int main(){
    int ve,e;
    cout<<"Enter the number of vertices and edges: ";
    cin>>ve>>e;

    vector<pair<int,int>> adj[ve];
    cout<<"Enter the edges"<<endl;
    for(int i=0;i<e;i++){
        int u,v,w;
        cin>>u>>v>>w;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    } 

    PrismAlgo(adj,ve);
}