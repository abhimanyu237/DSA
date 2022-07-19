#include <bits/stdc++.h>
using namespace std;
void addedge(vector <int> adj[],int u,int v){
    adj[u].push_back(v);
}
bool BfsGiven_soure(int s,bool arr[],vector<int>adj[],bool checks[],int v){
    queue<int>qg;
qg.push(s);
arr[s]=true;
while(qg.empty()==false){
    int x=qg.front();
    qg.pop();
    for(auto i:adj[x]){
     if(arr[i]==false){
         arr[i]=true;
         qg.push(i);
     }else if(checks[i]==true){
         return true;
     }
      checks[x]=true;
    }
   }
   for(int i=0;i<v;i++){
    checks[i]=false;
   }
   return false;
}
bool Bfs_Without_source(bool arr[],int v,vector<int>adj[],bool checks[]){
    for(int i=0;i<v;i++){
    if(arr[i]==false){
        if(BfsGiven_soure(i,arr,adj,checks,v)){
            return true;
        }
    }
}
return false;
}
int main(){
 int v=6;
vector<int> adj[v];
addedge(adj,0,1);
addedge(adj,0,2);
addedge(adj,1,2);
//addedge(adj,4,3);
//addedge(adj,5,4);
//addedge(adj,2,5);

//BFS
  bool arr[v],checks[v];
for(int i=0;i<v;i++){
    arr[i]=false;
    checks[i]=false;
}
if(Bfs_Without_source(arr,v,adj,checks))
cout<<"YES"<<endl;
else
cout<<"NO"<<endl;
    return 0;
}