#include <bits/stdc++.h>
using namespace std;
// void swap(int *a, int *b)
// {
//     int x = *a;
//     *a = *b;
//     *b = x;
// }
int  siz = 0, cap;
void insert(int arr[], int number)
{
    arr[siz] = number;
    if (siz != 0)
    {
        int p = floor((siz - 1) / 2),x=siz;
        while (arr[p] > arr[x] && p >= 0)
        {
         swap(arr[p],arr[x]);
        x=p;
        p = floor((p - 1) / 2);
      }
    }
    siz++;
}
int main()
{
    cout << "enter the size of heap\n";
    cin >> cap;
    int arr[cap];
    insert(arr, 2);
    insert(arr, 3);
    insert(arr, 4);
    insert(arr, 5);
    insert(arr, 6);
    insert(arr, 7);
    insert (arr,1);
    insert(arr,24);
    insert(arr,19);
    insert(arr,12);
    insert(arr,11);
  for(int i=0;i<siz;i++){
      cout<<arr[i]<<" ";
  }
    return 0;
}
