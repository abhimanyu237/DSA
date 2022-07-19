#include <bits/stdc++.h>
using namespace std;
void addedge(vector <int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int coun=0;
vector<string>path;
void Hemilton_cir(vector<int>adj[],int s,int v,int str,string &subans,bool visit[]){
     if(coun==v&&s==str){
       path.push_back(subans);
       return;
     }
      if(visit[s]==true){
           return;
     }
     coun++;
     visit[s]=true;
     string g=to_string(s);
     subans+=g;
     for(auto x:adj[s]){
    Hemilton_cir(adj,x,v,str,subans,visit);
     }
    coun--;
    for(int j=0;j<g.size();j++)
     subans.pop_back();
     
     visit[s]=false;

}
   
int main(){
 int v=6;
vector<int> adj[v];
// addedge(adj,0,2);
// addedge(adj,0,1);
// addedge(adj,1,2);
// addedge(adj,1,3);
// addedge(adj,2,3);
// addedge(adj,4,5);
// addedge(adj,4,6);
// addedge(adj,5,6);
addedge(adj,0,1);
addedge(adj,0,2);
addedge(adj,0,3);
addedge(adj,1,2);
addedge(adj,1,4);
addedge(adj,2,3);
addedge(adj,2,4);
addedge(adj,3,4);
addedge(adj,3,5);
addedge(adj,4,5);

//BFS
// int s;//source vertex
// cin>>s;
  bool arr[v];

for(int i=0;i<v;i++){
    arr[i]=false;
}
for(int i=0;i<v;i++){
    string subans;
    coun=0;
    Hemilton_cir(adj,i,v,i,subans,arr);
}
for(int i=0;i<path.size();i++){
    cout<<path[i]<<endl;
}
    return 0;
}