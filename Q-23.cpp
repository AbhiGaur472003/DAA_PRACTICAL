// Implement the previous problem using Kruskal's algorithm.

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int u,v,w;
    Node(int first,int second,int weight){
        u=first;
        v=second;
        w=weight;
    }
};

bool cmp(const Node a,const Node b){
    return a.w<b.w;
}

int find(int b,int parent[]){
    if(parent[b]==-1){
        return b;
    }
    return find(parent[b],parent);
}

bool DETECTCYCLE(int a,int b,int parent[],vector<int>& rank){
    int x=find(a,parent);
    int y=find(b,parent);

    if(x==y){
        return true;
    }

    if(rank[x]<rank[y]){
        parent[x]=y;
    }
    else if(rank[y]<rank[x]){
        parent[y]=x;
    }
    else{
        parent[x]=y;
        rank[y]++;
    }
    return false;
}

int main(){
    int ve,e;
    cout<<"Enter the number of vertice and edges: ";
    cin>>ve>>e;

    vector<Node> adj;
    cout<<"Enter the edge and weight"<<endl;
    for(int i=0;i<e;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj.push_back(Node(u,v,w));
    }

    sort(adj.begin(),adj.end(),cmp);

    int parent[ve];
    memset(parent,-1,sizeof(parent));

    vector<int> rank(ve,0);

    vector<pair<int,int>> mst;
    int sum=0;
    for(auto it=adj.begin();it!=adj.end();it++){
        // cout<<it->u<<" "<<it->v<<endl;
        if(!DETECTCYCLE(it->u,it->v,parent,rank)){
            mst.push_back({it->u,it->v});
            sum+=it->w;
        }
    }

    cout<<"Minimum Spanning Weigth: "<<sum<<endl;

}