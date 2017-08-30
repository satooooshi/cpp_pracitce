#include <iostream>
#include <iomanip>
#include <string>
#include<sstream>
using namespace std;


//****************************************************************************//
class LongLongInt{
public:
  int *data;
  int size;
  int *right;
  int *left;
  int op;
  void parser(char chr[]);
  void parseOut();
public:
  LongLongInt():data{NULL},size{0},op{1}{};
  LongLongInt(char c[]);
  LongLongInt(int d[],int s);
  LongLongInt(const LongLongInt &l);
  int getop(){return op;}
  friend LongLongInt operator+(LongLongInt &la ,LongLongInt &lb);
  friend LongLongInt operator-(LongLongInt &la ,LongLongInt &lb);
  friend bool operator<(const LongLongInt &la, const LongLongInt &lb);
  friend bool operator==(const LongLongInt &la, const LongLongInt &lb);
  friend void alignBoth(LongLongInt &la, LongLongInt &lb);
  friend int opeSet(LongLongInt &la, LongLongInt &lb);
  void operator=(const LongLongInt &l);
  friend ostream& operator<<(ostream &output,LongLongInt &l);
  ~LongLongInt(){delete[] data;}
};

class Integ{
private:
  LongLongInt l;
  int ope;
public:
  Integ()
  :l(){ope=1;}
  Integ(char c[])
  :l(c){ope=l.getop();}
  Integ(const LongLongInt &ll,int o)
  :l(ll){ope=o;}
friend int opeSet(Integ &ia ,Integ &ib);
friend Integ operator+(Integ &ia ,Integ &ib);
friend Integ operator-(Integ &ia ,Integ &ib);
Integ operator++();
Integ operator--();
Integ operator++(int);
Integ operator--(int);
friend bool operator==(const Integ &ia ,const Integ &ib);
friend bool operator<(const Integ &ia ,const Integ &ib);
friend bool operator>(const Integ &ia ,const Integ &ib);
void operator=(const Integ &i){this->l=i.l;this->ope=i.l.op;return ;}
friend ostream& operator<<(ostream &output,Integ &i);

};


//****************************************************************************//
int opeSet(LongLongInt &la, LongLongInt &lb){
  if(la.op==1&&lb.op==1)return 1;//+ +
  else if(la.op==1&&lb.op==-1)return 2;//+ -
  else if(la.op==-1&&lb.op==1)return 3;//- +
  else if(la.op==-1&&lb.op==-1)return 4;//- -
  else return -1;// error
}

Integ operator+(Integ &ia ,Integ &ib){
  if(opeSet(ia.l,ib.l)==1){return Integ(ia.l+ib.l,1);}
  else if(opeSet(ia.l,ib.l)==4){return Integ(ia.l+ib.l,-1);}
  else if(opeSet(ia.l,ib.l)==2){return Integ(ia.l-ib.l,(ia.l<ib.l)?-1:1);}
  else {return Integ(ia.l-ib.l,(ia.l<ib.l)?1:-1);}
}

Integ operator-(Integ &ia ,Integ &ib){
  if(opeSet(ia.l,ib.l)==1){return Integ(ia.l-ib.l,(ia.l<ib.l)?-1:1);}
  else if(opeSet(ia.l,ib.l)==4){return Integ(ia.l-ib.l,(ia.l<ib.l)?1:-1);}
  else if(opeSet(ia.l,ib.l)==2){return Integ(ia.l+ib.l,1);}
  else {return Integ(ia.l+ib.l,(ia.l<ib.l)?1:-1);}
}

ostream& operator<<(ostream &output,Integ &i){
  stringstream ss;
  ss<<i.l;
  string str=ss.str();
  str=str.substr(1);
  while(str[0]=='0'){str=str.substr(1);}
  if(str.length()==0)output<<"0";
  else output<<((i.ope==1)?'+':'-')<<str;
  return output;
}

bool operator==(const Integ &ia ,const Integ &ib){
  if(ia.l==ib.l)return true;
  else return false;


}

bool operator<(const Integ &ia ,const Integ &ib){
  if(ia.ope==-1&&ib.ope==1)return true;
  else if(ia.ope==1&&ia.ope==-1)return false;
  else return ia.l<ib.l;
}

bool operator>(const Integ &ia ,const Integ &ib){
  if(ia==ib)return false;
  if(ia.ope==-1&&ib.ope==1)return false;
  else if(ia.ope==1&&ia.ope==-1)return true;
  else return !(ia.l<ib.l);
}

Integ Integ::operator++(){
  char c[]="+1";
  Integ ii(c);
  *this=*this+ii;
  return *this;
}

Integ Integ::operator--(){
  char c[]="+1";
  Integ ii(c);
  *this=*this-ii;
  return *this;
}

Integ Integ::operator++(int){
  char c[]="+1";
  Integ ii(c);
  *this=*this+ii;
  return *this;
}

Integ Integ::operator--(int){
  char c[]="+1";
  Integ ii(c);
  *this=*this-ii;
  return *this;
}

//****************************************************************************//
LongLongInt::LongLongInt(char c[]){
  parser(c);
}

LongLongInt::LongLongInt(int d[],int s){
  size=s;
  data=new int[size];
  for(int i=0;i<size;++i){
    data[i]=d[i];
  }
}

LongLongInt::LongLongInt(const LongLongInt &l){
  size=l.size;
  data=new int[size];
  for(int i=0;i<size;++i)data[i]=l.data[i];
}

void alignBoth(LongLongInt &la, LongLongInt &lb){
  int len=(la.size>lb.size)?la.size:lb.size;
  int ia=la.size;
  int ib=lb.size;

  int *a=new int[len];
  int *b=new int[len];
  for(int i=0;i<len;++i){a[i]=0;b[i]=0;}

  while(ia){a[--len]=la.data[--ia];}
  len=(la.size>lb.size)?la.size:lb.size;
  while(ib){b[--len]=lb.data[--ib];}
  len=(la.size>lb.size)?la.size:lb.size;

  delete []la.data;
  delete []lb.data;

  la.data=new int[len];
  lb.data=new int[len];
  la.size=len;
  lb.size=len;

  for(int i=0;i<len;++i)la.data[i]=a[i];
  for(int i=0;i<len;++i)lb.data[i]=b[i];


  delete []a;
  delete []b;
}

void LongLongInt::parser(char chr[]){
  string str=chr;
  if(str[0]!='+'&&str[0]!='-')str[0]='+';//when 123 ->+123
  if(str[0]=='+'||str[0]=='-'){op=(str[0]=='+')?1:-1;str=str.substr(1);}//when -232343
  if(str[0]=='0')while(str[0]=='0')str=str.substr(1);//when 000004
  if(!str.length())str='0';//when -

  size=str.length()/8+1;
  data=new int[size];
  int mo=str.length()%8;

  string arr;
  if(mo)arr=str.substr(0,mo);//mo0,len%8
  else arr='0';
  data[0]=stoi(arr);
  for(int i=0;i<size-1;++i){
    arr=str.substr(mo+8*i,8);//str.substr(pos,length); str.substr(pos);substruct from pos to end
    data[i+1]=stoi(arr);
  }

  //for(int i=0;i<size;++i)cout<<data[i]<<" ";
    //cout<<endl;
}

void LongLongInt::parseOut(){
  stringstream ss;
  for(int i=0;i<size;++i)ss<<setw(8)<<setfill('0')<<data[i];
  string str=ss.str();
  delete []data;

  if(str[0]=='+'||str[0]=='-'){op=(str[0]=='+')?1:-1;str=str.substr(1);}//when -232343
  if(str[0]=='0')while(str[0]=='0')str=str.substr(1);//when 000004
  if(!str.length()){str='0';op=0;}//when -

  size=str.length()/8+1;
  data=new int[size];
  int mo=str.length()%8;

  string arr;
  if(mo)arr=str.substr(0,mo);//mo0,len%8
  else arr='0';
  data[0]=stoi(arr);
  for(int i=0;i<size-1;++i){
    arr=str.substr(mo+8*i,8);//str.substr(pos,length); str.substr(pos);substruct from pos to end
    data[i+1]=stoi(arr);
  }
}

LongLongInt operator+(LongLongInt &la ,LongLongInt &lb)
{

  alignBoth(la,lb);
  //for(int i=0;i<la.size;++i)cout<<la.data[i]<<" ";
  //cout<<endl;
  //for(int i=0;i<lb.size;++i)cout<<lb.data[i]<<" ";
  //cout<<endl;


  int N=la.size;
  int z[N];
  for(int i=0;i<N;++i)z[i]=0;

  int carry = 0;
  for (int i = N - 1; i >=0; i--) {
      z[i] = la.data[i] + lb.data[i] + carry;
      if (z[i] < 100000000) {
          carry = 0;
      } else {
          z[i] = z[i] - 100000000;
          carry = 1;
      }
    if(carry&&!i)z[i]+=100000000;//OVERFLOW(MSB)
  }
  //for(int i=0;i<N;++i)cout<<z[i]<<" ";
  //cout<<endl;
  LongLongInt l(z,N);
  l.op=1;
  return l;
}


LongLongInt operator-(LongLongInt &la ,LongLongInt &lb){

  alignBoth(la,lb);
  int N=la.size;
  int z[N];
  for(int i=0;i<N;++i)z[i]=0;
  int buf=1;

  if(la==lb){
    //do nothing
  }else if(la<lb){
    buf=-1;
    int borrow = 0;
    for (int i = N - 1; i >=0; i--) {
        z[i] = lb.data[i] - la.data[i] - borrow;
        if (z[i] >= 0) {
            borrow = 0;
        } else{
            z[i] = z[i] + 100000000;
            borrow = 1;
        }
    }
  }else{
   int borrow = 0;
   for (int i = N - 1; i >=0; i--) {
      z[i] = la.data[i] - lb.data[i] - borrow;
      if (z[i] >= 0) {
          borrow = 0;
      } else{
          z[i] = z[i] + 100000000;
          borrow = 1;
      }
    }
  }
  LongLongInt l(z,N);
  l.op=buf;
  if(la==lb)l.op=0;
  return l;
}

bool operator<(const LongLongInt &la,const LongLongInt &lb){
  //*************should inplumented in Integ
  //if(la.op==-1&&lb.op==1)return true;
  //else if(la.op==1&&la.op==-1)return false;

  if(la.size>lb.size)return false;
  else if(la.size<lb.size)return true;

  for (int i = 0; i < la.size; ++i){
    if(la.data[i]>lb.data[i])return false;
    else if(la.data[i]<lb.data[i])return true;
    else continue;
  }

  return false;//EQUAL
}


ostream& operator<<(ostream &output,LongLongInt &l){
  l.parseOut();
  char ope=(l.op==1)?'+':'-';
  output<<ope;
  string str;

  for(int i=0;i<l.size;++i){
    str=to_string(l.data[i]);
    output<<setw(8)<<setfill('0')<<str;
  }
  return output;
}

bool operator==(const LongLongInt &la, const LongLongInt &lb){

  if(la.size!=lb.size)return false;

  if(la.op!=lb.op)return false;
  else{
      for(int i=0;i<la.size;++i){
        if(la.data[i]!=lb.data[i])return false;
      }

  }
  return true;
}

void LongLongInt::operator=(const LongLongInt &l){
  delete data;
  size=l.size;
  data=new int[l.size];
  for(int i=0;i<size;++i){data[i]=l.data[i];}

  return ;
}


//****************************************************************************//
int main ()
{

char c[]="+123456789";
char cc[]="-987654321";

Integ i(c);
Integ ii(cc);
Integ iii;
iii=i+ii;
--iii;
iii--;
cout<<iii<<endl;




  return 0;
}
