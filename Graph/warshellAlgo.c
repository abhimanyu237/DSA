//it is give the matrix which tell there atleast one path exist from i to j

#include <stdio.h>
#define max_size 100
 int graph[max_size][max_size];
 void warshell(int v){
    for(int k=0;k<v;k++){
       for(int i=0;i<v;i++){
         for(int j=0;j<v;j++){
           if(graph[i][j]==0){
            if(graph[i][k]==1&&graph[k][j]==1){
                graph[i][j]=1;
            }
           }
             
         }
       }
    }
    for(int i=0;i<v;i++){
         for(int j=0;j<v;j++){
           
        printf("%d ",graph[i][j]);
             
         }
         printf("\n");
    }
 }
int main(){
int v;
printf("enter the number of vertex\n");
scanf("%d",&v);
printf("Enetr the edge from vertex i to j\n 1 2\n enter -1 -1 to end the edges input\n");
for(int i=0;i<v*(v-1);i++){
    int x,y;
    scanf("%d%d",&x,&y);
    if(x==-1&&y==-1)
    break;
    graph[x][y]=1;
    //graph[y][x]=1;

}
  warshell(v);
    return 0;
}