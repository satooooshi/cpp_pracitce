#include<iostream>
using namespace std;

//Base (superclass)
struct B{
  virtual void f()const{cout<<"B::f"<<endl;}//virtual means can be overrided
  void g()const{cout<<"B::g"<<endl;}
};

//derivative (subclass)
struct D:B{
  void f()const{cout<<"D::f"<<endl;}
  void g()const{cout<<"D::g"<<endl;}
};

struct DD:D{
  //void f()const override{cout<<"DD:f"<<endl;};
  void f()const{cout<<"DD:f"<<endl;}
  void g()const{cout<<"DD:g"<<endl;}
};

//a D is a kind of B, so call() can accept D.
//a DD is a kind of D , a D is a kind of B so call() can accept DD.
void call(const B &b){
  b.f();//if DD is not overrided, B::f will be outputted
  b.g();
}

int main(){

  B b;
  D d;
  DD dd;

//member function only followed by virtual keyword is to be overrided
  call(b);
  call(d);
  call(dd);

  cout<<endl;

  b.f();
  b.g();
  d.f();
  d.g();
  dd.f();
  dd.g();

  return 0;
}
