#include<iostream>
using namespace std;
#include <memory>// auto_ptr

template<typename T>
class Auto_ptr{
  T* ptr;
public:
  explicit Auto_ptr(T* p=0):ptr(p){}//p should contain address
  ~Auto_ptr(){delete ptr;}//array delete[]; else delete;
  T& operator*(){return *ptr;}
  T* operator->(){return ptr;}
};




//shared_ptr example
void exampleOne(){
  std::shared_ptr<int> p1 (new int);//p1 contains address
  *p1=10;  //* uses operator*
  *p1.get()=11;// == *p1=10;
  std::shared_ptr<int> p2 (p1);//p2=p1 the same address
  std::cout << "p2 points to " << *p2 << '\n';
  std::cout<<"p1 points to"<<*p1<<'\n';
  // (p1 is now null-pointer auto_ptr)
}


// auto_ptr::operator= example
void exapmleTwo(){
  std::auto_ptr<int> p;//default p==NULL
  std::auto_ptr<int> p2;
  p = std::auto_ptr<int> (new int);
  *p = 12;//* uses operator*
  p2 = p;//
  std::cout << "p2 points to " << *p2 << '\n';
  // (p is now null-pointer auto_ptr)

}

int main(){

  //Auto_ptr<int>p(new int);

  exampleOne();
  exapmleTwo();




  return 0;
}
