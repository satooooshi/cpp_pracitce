//**************************************
//
//516413990003 会川慧
//
//**************************************

#include<iostream>
#include<memory>
using namespace std;


template<typename T>
class Node{
public:
  T value;
  shared_ptr<Node<T>>next;
  Node(){};
  Node(T v):value(v){}
};

template<typename T>
class Stack{
private:
  shared_ptr<Node<T>>data;
  shared_ptr<Node<T>>head;
  shared_ptr<Node<T>>current;
  friend class Node<T>;
  int count;
public:
  Stack():count(0){}
  Stack(const Stack&)=delete;
  Stack& operator=(const Stack&)=delete;
  ~Stack(){}
  void push(T elem);
  bool pop(T& cell);
  void print();
};

template<typename T>
inline void Stack<T>::push(T elem){
  data=shared_ptr<Node<T>>(new Node<T>(elem));
  data->next=head;
  head=data;
  ++count;
}

template<typename T>
inline bool Stack<T>::pop(T& cell){
  if(count==0){cell={0};return false;}
  cell=head->value;
  head=head->next;
  --count;
  return true;
}

template<typename T>
inline void Stack<T>::print(){
  current=head;
  for(int i=0;i<count;++i){
    cout<<current->value<<endl;
    current=current->next;
  }
}


int main(){

  cout<<"stack string "<<endl;
  string str;
  Stack<string> a_stack;
  a_stack.push("hey");
  a_stack.push("g");
  a_stack.push("i did it!");
  a_stack.push("Hellow world!");
  cout<<a_stack.pop(str)<<" "<<str<<endl;
  cout<<a_stack.pop(str)<<" "<<str<<endl;
  cout<<a_stack.pop(str)<<" "<<str<<endl;
  a_stack.push("hey");
  a_stack.push("g");
  a_stack.push("i did it!");
  a_stack.push("Hellow world!");
  cout<<a_stack.pop(str)<<" "<<str<<endl;
  cout<<a_stack.pop(str)<<" "<<str<<endl;
  cout<<a_stack.pop(str)<<" "<<str<<endl;
  cout<<a_stack.pop(str)<<" "<<str<<endl;
  cout<<a_stack.pop(str)<<" "<<str<<endl;
  cout<<a_stack.pop(str)<<" "<<str<<endl;
  cout<<a_stack.pop(str)<<" "<<str<<endl;
  cout<<"remaining ones...."<<endl;


  cout<<"stack double "<<endl;
  Stack<double>b;
  double d;
  b.push(3.14);
  b.push(1.7);
  b.push(1.41421356);
  b.push(5.46);
  cout<<"pop-> "<<b.pop(d)<<endl;
  cout<<"pop-> "<<b.pop(d)<<endl;
  cout<<"pop-> "<<b.pop(d)<<endl;
  cout<<"pop-> "<<b.pop(d)<<endl;
  cout<<"pop-> "<<b.pop(d)<<endl;
  cout<<"pop-> "<<b.pop(d)<<endl;
  cout<<"pop-> "<<b.pop(d)<<endl;
  b.push(4);


  return 0;
}
