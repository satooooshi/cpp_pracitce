#include<iostream>
using namespace std;

class LongLongInt{
  char *num;
  int size;
public:
  LongLongInt(char str[]);
  explicit LongLongInt(const LongLongInt &l);
  LongLongInt& operator=(const LongLongInt &l)=delete;
  void display(){for(int i=size;i>=0;--i)cout<<num[i];cout<<endl;}
  ~LongLongInt(){delete[] num;}
  void add(const LongLongInt &l);
};

LongLongInt::LongLongInt(char str[])
:size{(int)strlen(str)}
  {
    num=new char[size+1];
    num[size]='0';//type char donot enter (int)1
    for(int i=0;i<size;++i)num[i]=(char)str[size-1-i];//mlb

  }
LongLongInt::LongLongInt(const LongLongInt &l) {
      size=l.size;
      num = new char[size+1];
      num[size]='0';
      for(int i=0;i<size;++i)num[i]=l.num[i];
  }

void LongLongInt::add(const LongLongInt &l){
  int max_digit;
  int min_digit;
  if(size>=l.size){
    max_digit=size;
    min_digit=l.size;
  }
  else{
    max_digit=l.size;
    min_digit=size;
    }
  char buf[min_digit];
  for(int i=0;i<max_digit;++i)buf[i]=l.num[i];buf[max_digit]='0';
  for(int i=0;i<min_digit;++i){
    if(size>=l.size){num[i]+=l.num[i];num[i]-='0';}
    else{
      buf[i]+=num[i];
      buf[i]-='0';
      for(int i=0;i<max_digit;++i)num[i]=buf[i];
      size=l.size;
      num[max_digit]='0';
    }
}
  for(int i=0;i<max_digit;++i)
    if(num[i]>(9+'0')){num[i]-=10;num[i+1]+=1;}
}

int main(){

char chr1[]="1";
char chr2[]="9999999999999";

LongLongInt l(chr1);
LongLongInt ll(chr2);
LongLongInt lll(l);
l.display();
ll.display();
lll.display();
l.add(ll);
l.display();
ll.display();

  return 0;
}
