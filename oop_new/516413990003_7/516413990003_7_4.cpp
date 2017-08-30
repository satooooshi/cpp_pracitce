#include<iostream>
#include<cstdlib>//rand()
using namespace std;

int main(){

  int num;
  int num_to_guess;
  char rep;
  rep='n';
  num=0;
  num_to_guess=0;

  srand((int)time(0));// void strand(//enter seed)
  num_to_guess=rand()%100+1;//1-100
  cout<<"I have a number between 1 and 100.\nPlease input our guess:";


  while(true){

  cin>>num;

  if(num_to_guess==num){
    cout<<"Execellent! You guessed the number!\nWould you like to play again(y or n)?   ";

    cin>>rep;

    if(rep=='y'){
      srand((int)time(0));// void strand(//enter seed)
      num_to_guess=rand()%100+1;//1-100
      cout<<"I have a number between 1 and 100.\nPlease input our guess:";
    }else{
      break;
    }

  }else if(num_to_guess>num){
    cout<<"Too low! Try again:";
  }else if(num_to_guess<num){
    cout<<"Too high! Try again:";
  }
 }
  return 0;
}
