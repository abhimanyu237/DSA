#include <bits/stdc++.h>
using namespace std;
void addedge(vector <int> adj[],int u,int v){
    adj[u].push_back(v);
}
bool BfsGiven_soure(int arr[],int v,vector<int>adj[]){
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
   int count=0;
   while(qg.empty()==false){
       int x=qg.front();
       //cout<<x<<" ";
       qg.pop();
       count++;
       for(auto i:adj[x]){
           arr[i]--;
           if(arr[i]==0)
           qg.push(i);
       }
   }
   if(count!=v&&v!=1)
   return true;
   else
   return false;
}
int main(){
 int v=6;
vector<int> adj[v];
addedge(adj,0,1);
addedge(adj,1,2);
addedge(adj,3,2);
addedge(adj,4,3);
addedge(adj,5,4);
addedge(adj,2,5);

//BFS
  int arr[v];
for(int i=0;i<v;i++){
    arr[i]=0;
}
if(BfsGiven_soure(arr,v,adj))
   cout<<"YES"<<endl;
   else
   cout<<"NO"<<endl;
    return 0;
}