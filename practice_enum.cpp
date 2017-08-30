#include<iostream>
using namespace std;


enum class Month{
  jan=1,feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec
};

class Invalid{
  int value;
public:
  //initialize value with x , its better limit value after :value{x}
  Invalid(int x){value=x;};//when declared in main loop, can be initialized by Invalid i{-100};
};

class Year{
  static const int min=1800;
  static const int max=2200;
public:
  class Invalid{};//make an object of type Invalid with default value {}
  //initialize y with x
  Year(int x):y{x} {if(x<min || max<=x)throw Invalid{};}//throw an object of Invalid initialized by {}.
  int year(){return y;}
private:
  int y;
};


class Date{
public:
  Date(int y, Month m, int d);
private:
  int y;
  Month m;
  int d;
};

int main(){

  Month m=Month::jan;
  Month mm=Month(7);
  Invalid i(-100);


  try{

      Year yy{3000};

  }catch(Invalid){
    cout<<"Invalid!!"<<endl;
  }

  return 0;
}
