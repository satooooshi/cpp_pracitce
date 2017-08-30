#include<iostream>
#include <algorithm>//sort()
using namespace std;

int main(){
  //'cin finish at \n' sizeof(arr)==the number of input character
  //initialize arr by ={}
  char arr[80]={};
  cin.getline(arr, sizeof(arr),'\n');
  sort(arr, arr + sizeof(arr));//sizeof(arr)
  for(int i=sizeof(arr)-1;i>=0;--i)
    cout<<arr[i];
  cout<<'\n';

  return 0;
}
