#include<iostream>
using namespace std;

int findFactorSum(int x){
  int sum=-x;//store (the sum of factors - x)
  for(int i=1;i<=x;++i){
    if(x%i==0){
      sum+=i;
    }
  }
return sum;
}

int main(){

  int n,m;
  int count;
  count=0;

  cout<<"Please input m, n:";
  cin>>n>>m;
  cout<<"Perfect number in [ "<<n<<" , "<<m<<" ]:";
  
  for(int i=n;i<=m;++i){
    if(i==findFactorSum(i)){
      cout<<i<<" ";
    }
  }
  cout<<endl;
  return 0;
}
