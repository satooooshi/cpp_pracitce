#include<iostream>
using namespace std;

//flip arr[0..i]
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

//the number of elem n
int findMax(int arr[], int n){
  int mi,i;
  for(mi=0,i=0;i<n;++i){
    if(arr[mi]<arr[i])
      mi=i;
  }
  return mi;
}

//the number of elem n
void pancakeSort(int arr[], int n){

  for(int curr_size=n;curr_size>1;--curr_size){
    int mi=findMax(arr,curr_size);
    if(mi!=curr_size-1){
      flip(arr,mi);
      flip(arr,curr_size-1);
    }
  }
}

int main(){

int arr[]={1,4,14,2,5};
int n=sizeof(arr)/sizeof(arr[0]);
pancakeSort(arr,n);
for(int i:arr)cout<<i<<" ";

  return 0;
}
