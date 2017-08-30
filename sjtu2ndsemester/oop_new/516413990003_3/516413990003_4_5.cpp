#include<iostream>
#include<cstdlib>//rand()
using namespace std;

int main(){

  int num;
  int one, ten, hun;
  //arr[2] least significant digit
  //arr[0] most significant digit
  int arr[3];
  //buf[2] least significant digit
  //buf[0] most significant digit
  int buf[3];
  int i, j,cnt;
  int pos_a, val_a;
  int num_to_guess;
  pos_a=0;
  val_a=0;

  //generate random three degit nubler
  srand((int)time(0));// void strand(//enter seed)
  num_to_guess=rand()%1000+1;
  one=num_to_guess%10;
  ten=(num_to_guess%100)/10;
  hun=(num_to_guess)/100;

  buf[2]=one;
  buf[1]=ten;
  buf[0]=hun;

  //code below for rand()test code
  //    for(int x : buf) {
  //      std::cout << x << "\n";
  //}


  cnt=7;
  while(true){
    if(cnt>0){
    cout<<"请输入你猜测的数字（"<<cnt<<"还有次机会）:";
    cin>>arr[0]>>arr[1]>>arr[2];
    }else{
    cout<<"很遗憾，你没有在规定次数内猜对。答案是"<<buf[0]<<buf[1]<<buf[2]<<"。\n";
    return 0;
    }
    cnt-=1;

  for(i=0;i<3;++i){
    if(arr[i]==buf[i])
      pos_a+=1;
  }

  for(i=0;i<2;++i){
    for(j=0;j<2;++j){
      if((arr[i]==buf[j]) && (arr[i]!=buf[i]))
        val_a+=1;
    }
  }

  cout<<pos_a<<"A"<<val_a<<"B\n";

  if(pos_a==3){
  cout<<"恭喜你，你猜对了。\n";
  return 0;
  }

  pos_a=0;
  val_a=0;

  }
  return 0;
}
