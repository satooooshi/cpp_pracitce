#include<iostream>
using namespace std;

class Rational{
private:
  int num;
  int den;
  void ReductFraction();
public:
  Rational(int n=0,int d=1){num=n;den=d;ReductFraction();}
  void create(int n, int d){num=n;den=d;ReductFraction();}
  void add(const Rational &r1, const Rational &r2);
  void multi(const Rational &r1, const Rational &r2);
  void display()const{cout<<num<<"/"<<den<<endl;}
  operator double()const{return double(num)/den;}
  friend Rational operator+(const Rational &r1, const Rational &r2);
  friend Rational operator*(const Rational &r1, const Rational &r2);
  friend bool operator<(const Rational &r1, const Rational &r2);
  friend bool operator==(const Rational &r1, const Rational &r2);
  friend istream& operator>>(istream &input, Rational &r1);
  friend ostream& operator<<(ostream &output, const Rational &r1);
};

void Rational::add(const Rational &r1, const Rational &r2){
  num=r1.num*r2.den+r2.num*r1.den;
  den=r1.den*r2.den;
  ReductFraction();
}
void Rational::multi(const Rational &r1, const Rational &r2){
  num=r1.num*r2.num;
  den=r1.den*r2.den;
  ReductFraction();
}
void Rational::ReductFraction(){
  int tmp=(num>den)?den:num;
  for(;tmp>1;--tmp)if(num%tmp==0&&den%tmp==0){num/=tmp;den/=tmp;break;}
}

Rational operator+(const Rational &r1, const Rational &r2){
  Rational r;
  r.num=r1.num*r2.den+r2.num*r1.den;
  r.den=r1.den*r2.den;
  r.ReductFraction();
  return r;
}
Rational operator*(const Rational &r1, const Rational &r2){
  Rational r;
  r.num=r1.num*r2.num;
  r.den=r1.den*r2.den;
  r.ReductFraction();
  return r;
}
bool operator<(const Rational &r1, const Rational &r2){
  return (r1.num*r2.den<r2.num*r1.den)?true:false;
}
bool operator==(const Rational &r1, const Rational &r2){
  return (r1.num==r2.num&&r1.den==r2.den);
}
istream& operator>>(istream &input, Rational &r1){
  input>>r1.num>>r1.den;
  r1.ReductFraction();
  return input;
}
ostream& operator<<(ostream &output, const Rational &r1){
  if(r1.den==1)output<<r1.num<<endl;
  else output<<r1.num<<"/"<<r1.den;
  return output;
}

/*
class Complex{
  Rational real;
  Rational imag;
public:
  Complex(int r1=0, int r2=1, int i1=0, int i2=1):
    :real(r1,r2),imag(i1,i2){}
};
*/
int main(){
/*
Rational r(7,28),rr(4,16);
Rational *p=new Rational[3];
p[0]=Rational(8,32);
p[1]=r+rr;//Rational(1,32);
p[2].multi(p[0],p[1]);
(p+1)->display();//  *p.display
delete []p;
*/
Rational r(2,11);
Rational rr(5,16);
Rational rrr;
rrr=(r+rr+rr)*r;

cout<<rrr<<", "<<double(rrr)<<endl;

  return 0;
}
