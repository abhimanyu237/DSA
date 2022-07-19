// to find the minimum spaning tree we use prims algorithm's
#include <stdio.h>
#include  <stdbool.h>
#define max_size 50
int W[max_size][max_size];
void Path(int ind,int s,int predice[]){
    if(ind==s){
        printf("%d",s);
        return;
    }else{
        Path(predice[ind],s,predice);
        printf("--->%d",ind);
    }
}
 void Dijkstra(bool status[],int Length[],int predice[],int n,int s){
    int flag=0;
    Length[s]=0;
    while(1){
        int current=-1;
        int min=9999;
        for(int i=0;i<n;i++){
            if(Length[i]<min&&status[i]==false){
                min=Length[i];
                current=i;
            }
        }
         
        if(current==-1){
           if(flag==n){
                printf("Shortest path for all vertex from source vetex\n");
             for(int i=0;i<n;i++){     
                Path(i,s,predice);
                printf(" length = %d",Length[i]);
                printf("\n"); 
             }
              return;
           }else{
               printf(" graph is not connected\n");
               return;
           }
        }
        status[current]=true;
        flag++;
        for(int i=0;i<n;i++){
            if(W[current][i]>0&&(W[current][i]+Length[current])<Length[i]&&status[i]==false){
                predice[i]=current;
                Length[i]=W[current][i]+Length[current];
            }
        }
    }
    
/*0 1
6
0 3
3
0 2
2
0 4
10
1 3
11
1 5
9
3 2
14
3 4
7
3 5
5
2 4
8
4 5
4
-1 -1 -1
*/
}
int main(){
    int n;
    printf("enter the no of vetex in graph\n");
    scanf("%d",&n);
    printf("enter the connected vertex by edge and weight Ex- 0 5 (there is an edge b/w vertex 0 and 5)\nif done then press -1 -1\n");
     for(int i=0;i<(n*(n-1)/2);i++){
         int x,y,w;
    scanf("%d %d %d",&x,&y,&w);
       if(x>=n||y>=n){
           printf("enterthe valid vertex\n");
           i--;
       }
       if(x==-1&&y==-1){
           break;
       }
       W[x][y]=w;
       W[y][x]=w;
     } 
    bool status[n];
    for(int i=0;i<n;i++){
        status[i]=false;
    }
    int Length[n];
    for(int i=0;i<n;i++){
        Length[i]=9999;
    }
    int predice[n];
    for(int i=0;i<n;i++){
        predice[i]=-1;
    }
    printf("enter the source vertex\n");
    int s;
    scanf("%d",&s);
    Dijkstra(status,Length,predice,n,s);
   
    return 0;
}