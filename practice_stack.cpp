#include<iostream>
#include<cstdlib>
using namespace std;

const int STACK_SIZE =100;

class Stack{
private:
  int count;
  int data[STACK_SIZE];
public:
  //Constructor, copy constructor, destructor, =operator is to be created automatically
  //explicit -> Stack s(10); OK,  Stack s=10; NG,
  explicit Stack(const int c);// need no argument so no type declared (ex void Stack();)
  Stack(const Stack& old_stack);//copy constructor
  void push(const int item);
  int pop();
  ~Stack();//deconstructor
  Stack operator=(const Stack& old_stack);//default operator
};

Stack::Stack(const int c):count(c){};

inline Stack::Stack(const Stack& old_stack){
  for(int i=0;i<old_stack.count;++i)
    data[i]=old_stack.data[i];
  count=old_stack.count;
}

inline void Stack::push(const int item){
  data[count]=item;
  ++count;
}

inline int Stack::pop(){
  --count;
  return data[count];
}

inline Stack::~Stack(){
  if(count!=0)
    cerr<<"Destroying unempty stack!"<<endl;
}

inline Stack Stack::operator=(const Stack& old_stack){
  for(int i=0;i<old_stack.count;++i)
    data[i]=old_stack.data[i];
  count=old_stack.count;
  return *this;
}
int main(){
Stack s1(5);
s1.push(1);
s1.push(2);
s1.push(3);
cout<<"s1 pop->"<<s1.pop()<<endl;
cout<<"s1 pop->"<<s1.pop()<<endl;

Stack s2(s1);//using copy constructor

Stack s3=s1;//using operator


cout<<"s2 pop-> "<<s2.pop()<<endl;
cout<<"s3 pop-> "<<s3.pop()<<endl;

  return 0;
}
