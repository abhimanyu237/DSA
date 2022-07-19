#include <bits/stdc++.h>
using namespace std;
void addedge(vector <int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void BfsGiven_soure(int s,bool arr[],vector<int>adj[],int distance[]){
    queue<int>qg;
qg.push(s);
distance[s]=0;
arr[s]=true;
while(qg.empty()==false){
    int x=qg.front();
    cout<<x<<" ";
    qg.pop();
    for(auto i:adj[x]){
     if(arr[i]==false){
         distance[i]=distance[x]+1;
         arr[i]=true;
         qg.push(i);
     }
    }
   }
   return ;
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
  int distance[v];
for(int i=0;i<v;i++){
    arr[i]=false;
    distance[i]=-1;
}

BfsGiven_soure(s,arr,adj,distance);
cout<<endl;
for(int i=0;i<v;i++){
    cout<<distance[i]<<" ";
}
//if distance b/w ith and jth vertex is -1 then it means jth vertex is not reachable from ith vertex
    return 0;
}