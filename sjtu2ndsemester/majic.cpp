#include<iostream>
using namespace std;

/**************

arr[5][5]={0};//the same value as n_max


***************/


int main(){

  int n_max;
  int arr[3][3]={0};//the same value as n_max
  int z;
  int i;
  int j;
  n_max=3;
  i=n_max/2;
  j=n_max-1;
  arr[i][j]=1;// start from 2nd row 3rd line


  for(z=2;z<=(n_max*n_max);++z){
    i+=1;
    j+=1;
    if(j>n_max-1){
      j=0;
    }
    if(i>n_max-1){
      i=0;
    }
    if(arr[i][j]!=0){
      i-=1;
      j-=1;

      j-=1;
    }
    if(i<0){
      i+=n_max;//n
    }
    if(j<0){
      j+=n_max;//n
    }
    //cout<<i<<i<<'\n';
    arr[i][j]=z;
    }


for(j=0;j<n_max;++j){
  for(i=0;i<n_max;++i){
    cout<<arr[i][j]<<' ';//縦がj　横がi
  }
cout<<'\n';

}
cout<<'\n';


  return 0;
}
