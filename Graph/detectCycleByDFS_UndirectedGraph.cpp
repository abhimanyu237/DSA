#include <bits/stdc++.h>
using namespace std;
void addedge(vector <int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
bool DfsGiven_soure(int s,bool arr[],vector<int>adj[],int parent){
      arr[s]=true;
      //cout<<s<<" ";
    for(auto i:adj[s]){
     if(arr[i]==false){
        if(DfsGiven_soure(i,arr,adj,s)==true){
            return true;
        }
     }else if(parent!=i){
         return true;
     }
    }
    return false;
   }
bool Dfs_Without_source(bool arr[],int v,vector<int>adj[]){
   
    for(int i=0;i<v;i++){
         if(arr[i]==false){
        if (DfsGiven_soure(i,arr,adj,-1))
          return true;
      
        }
     }
     return false;
}
int main(){
 int v=7;
vector<int> adj[v];
//addedge(adj,0,2);
//addedge(adj,0,1);
//addedge(adj,1,2);
//addedge(adj,1,3);
//addedge(adj,2,3);
//addedge(adj,4,5);
//addedge(adj,4,6);
//addedge(adj,5,6);
addedge(adj,0,2);
addedge(adj,0,1);
addedge(adj,1,3);
addedge(adj,4,3);
addedge(adj,2,5);
addedge(adj,4,6);
//addedge(adj,5,6);

// //BFS
// // int s;//source vertex
// // cin>>s;
  bool arr[v];
for(int i=0;i<v;i++){
    arr[i]=false;
}

       if(Dfs_Without_source(arr,v,adj))
           cout<<"YES"<<endl;
           else
           cout<<"NO";
    return 0;
}