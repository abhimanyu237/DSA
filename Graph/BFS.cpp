#include <bits/stdc++.h>
using namespace std;
void addedge(vector <int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void BfsGiven_soure(int s,bool arr[],vector<int>adj[]){
    queue<int>qg;
qg.push(s);
arr[s]=true;
while(qg.empty()==false){
    int x=qg.front();
    cout<<x<<" ";
    qg.pop();
    for(auto i:adj[x]){
     if(arr[i]==false){
         arr[i]=true;
         qg.push(i);
     }
    }
   }
   return ;
}
void Bfs_Without_source(bool arr[],int v,vector<int>adj[]){
    for(int i=0;i<v;i++){
    if(arr[i]==false){
        BfsGiven_soure(i,arr,adj);
    }
}
}
int main(){
 int v=7;
vector<int> adj[v];
addedge(adj,0,2);
addedge(adj,0,1);
addedge(adj,1,2);
addedge(adj,1,3);
addedge(adj,2,3);
addedge(adj,4,5);
addedge(adj,4,6);
addedge(adj,5,6);

//BFS
int s;//source vertex
cin>>s;
  bool arr[v];
for(int i=0;i<v;i++){
    arr[i]=false;
}
BfsGiven_soure(s,arr,adj);
for(int i=0;i<v;i++){
    arr[i]=false;
}
cout<<endl;
Bfs_Without_source(arr,v,adj);
    return 0;
}