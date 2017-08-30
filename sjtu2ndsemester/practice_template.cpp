#include<iostream>

/*
#define define_max(type) type max(type d1, type d2){\
  if(d1>d2)                                         \
    return d1;                                      \
  return d2;                                        \
}
define_max(float);
int main(){
  float f=max(3.5, 8.7);
  std::cout<<f<<'\n';
  return 0;
}
*/

/*
template<typename kind>
kind max(kind d1, kind d2){
  if(d1>d2)
    return d1;
  return d2;
}
int main(){
  float f=max(3.5, 5.4);
  std::cout<<f<<'\n';
  return 0;
}
*/

#define STACK_SIZE 10

//デフォルトパラメータ 型を指定しないと自動的に型がlist=in_memory_listになる
//template<typename address, typename list=in_memory_list>
template<typename kind>
class stack{
private:
  kind count;
  kind data[STACK_SIZE];
public:
  stack(){count=0;}//initializer
  void push(const kind item);
  kind pop(){--count;return data[count];}
};

//member function outside class{}; must be also followed by template<>
template<typename kind>
inline void stack<kind>::push(const kind item){
  data[count]=item;
  ++count;
}
int main(){
  stack<int> a_stack;
  a_stack.push(111);
  a_stack.push(222);
  std::cout<<a_stack.pop()<<'\n';
  return 0;
}
//void push(const kind item){
  //data[count]=item;
  //++count;
//}
