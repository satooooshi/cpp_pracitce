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
  shared_ptr<Node<T>>next;//defalut next=NULL;
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
  Stack():count(0){}//constructor
  Stack(const Stack&)=delete;//copy constructor
  Stack& operator=(const Stack&)=delete;//assign operator=
  ~Stack(){}//destructor
  void push(T elem);
  bool pop(T& cell);
  void print();
};

//member function outside class{}; must be also followed by template<>
template<typename T>
inline void Stack<T>::push(T elem){
  data=shared_ptr<Node<T>> (new Node<T>(elem));
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
  /*
  string str;
  Stack<string> a_stack;
  a_stack.push("hey");
  a_stack.push("g");
  a_stack.push("i did it!");
  a_stack.push("Hellow world!");
  a_stack.print();
  cout<<a_stack.pop(str)<<" "<<str<<endl;
  cout<<a_stack.pop(str)<<" "<<str<<endl;
  cout<<a_stack.pop(str)<<" "<<str<<endl;
  cout<<a_stack.pop(str)<<" "<<str<<endl;
  cout<<a_stack.pop(str)<<" "<<str<<endl;
  cout<<a_stack.pop(str)<<" "<<str<<endl;
  cout<<"all poped out!!"<<endl;
  a_stack.print();
*/

char str;
Stack<char> a_stack;
a_stack.push('B');
a_stack.push('3');
a_stack.push('i');
a_stack.print();
cout<<a_stack.pop(str)<<" "<<str<<endl;
cout<<a_stack.pop(str)<<" "<<str<<endl;
cout<<a_stack.pop(str)<<" "<<str<<endl;
cout<<a_stack.pop(str)<<" "<<str<<endl;
cout<<a_stack.pop(str)<<" "<<str<<endl;
cout<<a_stack.pop(str)<<" "<<str<<endl;
cout<<"all poped out!!"<<endl;
a_stack.print();


  return 0;
}
