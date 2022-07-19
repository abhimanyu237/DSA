// it is used to find all pair shortest path time complexuty O(v^3)
#include <stdio.h>
#define max_size 100
#define infinite 9999999
int D[max_size][max_size];
int Pre[max_size][max_size];
 void floyd(int v){
     for(int k=0;k<v;k++){
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if((D[i][k]+D[k][j])<D[i][j]){
                    D[i][j]=D[i][k]+D[k][j];
                    Pre[i][j]=Pre[k][j];
                }
            }
        }
     }
      for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
               printf("%d ",D[i][j]);
            }
            printf("\n");
        }
        printf("predecessor matrix\n");
         for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
             printf("%d ",Pre[i][j]);   
                
            }
            printf("\n");
        }
 }
int main(){
 int v;
 printf("enter the number of vetex in graph\n");
 scanf("%d",&v);
 for(int i=0;i<v;i++){
    for(int j=0;j<v;j++){
    D[i][j]=infinite;
    Pre[i][j]=-1;
    }
 }
 printf("enter the edge and weight (1 2 5)\nto end the input enter -1 -1 -1\n");
 for(int i=0;i<v*(v-1);i++){
    int x,y,w;
    scanf("%d%d%d",&x,&y,&w);
    if(x==-1&&y==-1&&w==-1)
    break;
    D[x][y]=w;
    Pre[x][y]=x;
 }
 floyd(v);
 return 0;
}