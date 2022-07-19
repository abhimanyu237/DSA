#include <stdio.h>
#define max_size 100
#define infinite 999999
int graph[max_size][max_size];
int predecessor[max_size];
int Ispresent[max_size];
int Queue[max_size];
int D[max_size];
int front=-1,rare=-1;
int Queue_front(){
  if(front==rare){
    return -1;//means empty
  }else{
    
    return Queue[front+1];
  }
}
int IsEmpty(){
    if(front>=rare){
     return 1;
    }else{
        return -1;
    }
}
void Queue_pop(){
   if(front<rare){
    front+=1;
  } 
}
void Queue_push(int a){
    if(rare!=max_size){
        rare+=1;
        Queue[rare]=a;
    }
}
int Bellman_ford(int v,int s){
     D[s]=0;
     int count=0;
     Queue_push(s);
     Ispresent[s]=1;
     while(IsEmpty()==-1){
        int current=Queue_front();
        //printf("%d",current);
        if(s==current){
            count++;
        }
        if(count>v){
           return -1;
        }
           Queue_pop();
           Ispresent[current]=0;
           for(int i=0;i<v;i++){
            if((graph[current][i]+D[current])<D[i] && graph[current][i]!=0){
                     if(Ispresent[i]==0){
                        Queue_push(i);
                        Ispresent[i]=1;
                     }
                     D[i]=graph[current][i]+D[current];
                     predecessor[i]=current;
            }
           }
     }
     return 1;
}
void path(int i,int s){
    if(i==s){
        printf("%d",i);
        return;
    }
    path(predecessor[i],s);
    printf("-->%d",i);
}
int main(){
int v;
 printf("enter the number of vetex in graph\n");
 scanf("%d",&v);
 printf("enter the edge and weight (1 2 5)\nto end the input enter -1 -1 -1\n");
 for(int i=0;i<v*(v-1);i++){
    int x,y,w;
    scanf("%d%d%d",&x,&y,&w);
    if(x==-1&&y==-1&&w==-1)
    break;
    graph[x][y]=w;
 }
 for(int i=0;i<v;i++){
    D[i]=infinite;
    predecessor[i]=-1;
    Ispresent[i]=0;
 }
 printf("enter the source vertex\n");
 int s;
 scanf("%d",&s);
  if(Bellman_ford(v,s)==1){
    for(int i=0;i<v;i++){
        if(s>v-1){
            printf("invailid source vetex\n");
            break;
        }else if(D[i]==infinite){
            printf("there is no path from the source %d to the vertex %d\n",s,i);
        }else{
        path(i,s);
        printf(" Weight %d \n",D[i]);
        }
    }
  }else{
    printf("graph contains negative cycle\n");
  }
return 0;
}
/*0 4 7
0 1 8
0 2 9
1 5 9
2 1 -4
2 0 5
2 3 3
3 2 6
3 1 3
3 5 4
4 7 16
5 6 -8 
5 7 5
5 0 4
6 7 2
6 3 5*/