/* A C++ program for Pancake Sorting */
#include<iostream>
using namespace std;

//reverses arr[0..i]
void flip(int arr[], int i){
  int temp,start=0;
  while(start<i){
    temp=arr[start];
    arr[start]=arr[i];
    arr[i]=temp;
    start++;
    i--;
  }
}

//returns index of arr[max]
int findMax(int arr[], int n){
  int max, i;
  for(max=0,i=0;i<n;++i){
    if(arr[i]>arr[max])
      max=i;
  }
  return max;
}

void pancakeSort(int *arr, int n){
  for(int current_size=n;current_size>1;--current_size){
    int max=findMax(arr,current_size);
    if(max!=current_size-1){
      flip(arr,max);
      flip(arr,current_size-1);
    }
  }
}


/* A utility function to print an array of size n */
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout<<arr[i]<<" ";
}

// Driver program to test above function
int main()
{
    int arr[] = {23, 10, 20, 11, 12, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    pancakeSort(arr, n);
    puts("Sorted Array ");
    printArray(arr, n);

    return 0;
}
