#include <bits/stdc++.h>
using namespace std;
void addedge(vector <int> adj[],int u,int v){
    adj[u].push_back(v);
}
void BfsGiven_soure(int arr[],int v,vector<int>adj[]){
    queue<int>qg;
    int a=0;
while(a<v){
    for(auto i:adj[a]){
     arr[i]++;
    }
    a++;
   }
   for(int i=0;i<v;i++){
       if(arr[i]==0)
          qg.push(i);
   }
   while(!qg.empty()){
       int x=qg.front();
       cout<<x<<" ";
       qg.pop();
       for(auto i:adj[x]){
           arr[i]--;
           if(arr[i]==0)
           qg.push(i);
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
  int arr[v];
for(int i=0;i<v;i++){
    arr[i]=0;
}
BfsGiven_soure(arr,v,adj);
    return 0;
}