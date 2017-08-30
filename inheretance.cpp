#include<iostream>
using namespace std;

class People{
protected:
  char *name;
  int age;
public:
  People(const char *s, int a ){
    name =new char[strlen(s)+1];
    strcpy(name,s);
    age=a;
    cout<<"People, name: "<<name<<", age: "<<age<<endl;
  }
  ~People(){delete []name;}
};

class Student:public People{
private:
  int s_no;
  char *class_no;

public:
  Student(const char *s, int a, int n, const char *cls)
  :People(s,a)
  {
    s_no=n;
    class_no=new char[strlen(cls)+1];
    strcpy(class_no,cls);
    cout<<"student:"<<endl;
  }
  ~Student(){delete []class_no;}
};

int main(){

  People p("josh", 19);

//:People(s,a) in Student class calls constructor of People
//基底クラスの引数付きコンストラクタを呼びたいときは、派生クラスコンストラクタの後ろに
// : <base class>(arguments,,)
//と書く

//派生クラス(derived class)のコンストラクタを呼ぶ前に基底クラス(base class)のコンストラクタが呼ばれ、
//派生クラスのデストラクタが呼ばれた後に基底クラスのデストラクタが呼ばれる

//コンストラクタでは、仮想関数(virtual function)は正しく働くとは限らない。
//必ず正しく働くのは、派生末端のコンストラクタ内のみ。
  Student s("wang",3,30,"F12345");




  return 0;
}
