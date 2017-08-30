#include<iostream>
using namespace std;

void getNumber(){
  double n;
  do{
    cout<<"请输入一个大于等于10并且小于30的正整数 : ";
    cin>>n;

    int n_float;
    n_float=static_cast<int>(n);

    if(!cin){
      cin.clear();//recover istream
      cin.sync();//clear buffer
    }

    if((n-n_float)!=0)//if input number isn't an integer
      n=-1;

  }while(n>=30 || n<10);

  cout<<"正整数 :"<<n<<endl;
}

int main(){

  getNumber();

  return 0;
}
