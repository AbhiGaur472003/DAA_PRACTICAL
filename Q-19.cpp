// After end term examination, Akshay wants to party with his friends. All his friends are living as
// paying guest and it has been decided to first gather at Akshay’s house and then move towards party
// location. The problem is that no one knows the exact address of his house in the city. Akshay as a
// computer science wizard knows how to apply his theory subjects in his real life and came up with
// an amazing idea to help his friends. He draws a graph by looking in to location of his house and
// his friends’ location (as a node in the graph) on a map. He wishes to find out shortest distance and
// path covering that distance from each of his friend’s location to his house and then whatsapp them
// this path so that they can reach his house in minimum time. Akshay has developed the program
// that implements Dijkstra’s algorithm but not sure about correctness of results. Can you also
// implement the same algorithm and verify the correctness of Akshay’s results? (Hint: Print shortest
// path and distance from friends’ location to Akshay’s house)

#include<bits/stdc++.h>
using namespace std;

bool fun(pair<int,int>& a,pair<int,int>& b){
    return b.second>a.second;
}
void SORTQUEUE(queue<pair<int,int>>& q){
    vector<pair<int,int>> v;
    while(!q.empty()){
        v.push_back(q.front());
        q.pop();
    }

    sort(v.begin(),v.end(),fun);

    for(int i=0;i<v.size();i++){
        q.push(v[i]);
    }
}
void Dijkstra(vector<pair<int,int>> adj[],int v,int s){
    vector<int> dis(v,INT_MAX);
    queue<pair<int,int>> q;
    dis[s]=0;
    q.push({s,dis[s]});
    while(!q.empty()){
        int i=q.front().first;
        int d=q.front().second;
        q.pop();
        for(auto it : adj[i]){
            if(dis[it.first]>d+it.second){
                dis[it.first]=d+it.second;
                q.push({it.first,dis[it.first]});
            }
        }

        SORTQUEUE(q);
    }

    for(int i=0;i<dis.size();i++){
        cout<<dis[i]<<" ";
    }
}
int main(){
    int vr,e;
    cin>>vr>>e;

    vector<pair<int,int>> adj[vr];

    for(int i=0;i<e;i++){
        int u,v,w;
        cin>>u>>v>>w;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});

    }

    int s=0;
    Dijkstra(adj,vr,s);
}