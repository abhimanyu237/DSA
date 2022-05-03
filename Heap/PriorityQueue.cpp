#include <bits/stdc++.h>
using namespace std;

// void swap(int *a, int *b)
// {
//     int x = *a;
//     *a = *b;
//     *b = x;
// }
int  siz = 0, cap=0;
//heapify the node with index i
void heapify(int arr[],int i){
    int maxi=i;
    int left=2*i+1,right=2*i+2;
    if(left<siz&&arr[left]>arr[maxi]){
        maxi=left;
    }
     if(right<siz&&arr[right]>arr[maxi]){
        maxi=right;
    }
    if(i!=maxi){
        swap(arr[i],arr[maxi]);
        heapify(arr,maxi);
    }
}
void Push(int arr[], int number)
{
    if(siz<cap){
    arr[siz] = number;
    if (siz != 0)
    {
        int p = floor((siz - 1) / 2),x=siz;
        while (arr[p] < arr[x] && p >= 0)
        {
         swap(arr[p],arr[x]);
        x=p;
        p = floor((p - 1) / 2);
      }
    }
    siz++;
    }
}
void Pop(int arr[]){
   int i=0;
    if (siz != 0)
    {
        arr[0]=arr[siz-1];
        siz--;
        if(siz!=0)
        heapify(arr,0);
    }
}
int Size(){
    return siz;
}
int Top(int arr[]){
    return arr[0];
}
bool Isempty(){
    if(siz!=0){
        return false;
    }else{
        return true;
    }
}
int main()
{
    cout <<"enter the size of heap\n";
    cin >> cap;
    int arr[cap];
    Push(arr, 2);
    Push(arr, 3);
    Push(arr, 4);
    Push(arr, 5);
    Push(arr, 6);
    Push(arr, 7);
    Push(arr,1);
    Push(arr,24);
    Push(arr,19);
    Push(arr,12);
    Push(arr,11);
    arr[0]=13;
    heapify(arr,0);//heapify the 0 index node
    Pop(arr);
    printf("%d\n",Top(arr));
    printf("%d\n",Size());
  for(int i=0;i<siz;i++){
      cout<<arr[i]<<" ";
  }
    return 0;
}
//stl inbuild function 
// priority-queue<int> pq;//max heap pq(for min heap multiply by -1 to all element)
//pq.push(value);(priority-queue <int> pq(arr,arr+n) //it is way to copy array element in pq)
//pq.top();
//pq.pop();

