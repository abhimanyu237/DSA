#include <bits/stdc++.h>
using namespace std;
int cap=0;
int siz=0,rare=0,front;
    void insertFront(int arr[],int num){
        if(siz==0){
            arr[front]=num;
            siz++;
        }else if(siz<cap){
          front=((front-1+cap)%cap);   
          arr[front]=num;
          siz++;
        }
    }
    void insertRare(int arr[],int num){
        if(siz==0){
            arr[rare]=num;
            siz++;
        }else if(siz<cap){
          rare=(rare+1);   
          arr[rare]=num;
          siz++;
        }
    }
    void deleteFront(int arr[]){
        if(siz==0){
            printf("deque is empty\n");
        }else {
          front=((front+1)%cap);   
          siz--;
        }
    }
    void deleteRare(int arr[]){
        if(siz==0){
             printf("deque is empty\n");
        }else{
          rare--;  
          siz--;
        }
    }
    void Front(int arr[]){
        if(siz!=0)
        printf("%d",arr[front]);
    }
     void Rare(int arr[]){
         if(siz!=0)
        printf("%d",arr[rare]);
    }
void Sized(){
    printf("%d",siz);
}
int main(){
    cin>>cap;
 int arr[cap];
  insertFront(arr,3);
  insertRare(arr,7);
  insertRare(arr,8);
  insertRare(arr,0);
  insertFront(arr,1);
  insertFront(arr,6);
  insertRare(arr,9);
  insertRare(arr,2);
  insertFront(arr,4);
  insertFront(arr,43);
  Front(arr);Rare(arr);deleteFront(arr);deleteRare(arr);
  Front(arr);Rare(arr);
  deleteFront(arr);deleteRare(arr);
  deleteFront(arr);deleteRare(arr);
  Front(arr);Rare(arr);
  Sized();
  return 0;

}
