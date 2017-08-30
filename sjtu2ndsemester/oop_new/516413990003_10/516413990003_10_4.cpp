#include<iostream>
using namespace std;

class Node{
public:
  string city;
  int value;
  Node *next;
  Node(string s, int v):city(s),value(v){}
};

class List{
private:
  Node *head;//biggest city
  Node *tail;//smallest city
  Node *current;
public:
  List():head(NULL),tail(NULL),current(NULL){}
  ~List();
  void createFromBig(string s, int v);
  void printAll();
  void deleteMin();
  void popTail();
};

List::~List(){
  while(head->next){
    current=head;
    delete current;
    head=head->next;
  }
}

void List::createFromBig(string s, int v){
  Node *new_node=new Node(s,v);
  if(tail==NULL){
    head=new_node;
    new_node->next=NULL;//tail element
    tail=new_node;
    head=new_node;
    return ;
  }
  if(v>=head->value){//<=
    new_node->next=head;
    head=new_node;
    return ;
  }else if(v<head->value){//>
    current=head;
    while(true){
      if(current->next==NULL){//reach tail
        current->next=new_node;
        new_node->next=NULL;
        tail=new_node;
        return ;
      }
      if(v>=current->next->value){//<
        new_node->next=current->next;
        current->next=new_node;
        return ;
      }
      current=current->next;
    }
  }
}

void List::popTail(){
  current=head;
  while(true){
    if(current->next->next==NULL){
      tail=current;
      break;
    }
    current=current->next;
  }
  delete current->next;
  tail->next=NULL;
}

void List::printAll(){
  current=head;
  while(current){
    cout<<current->city<<" ";
    current=current->next;
  }
  cout<<endl;
}


int main(){


  string a_string;//separated by space
  int pop;
  List list;
  cout<<"Please input a city name and its population"<<endl;
  while(a_string!="@"){
  cout<<" > ";
  cin>>a_string;
  if(a_string=="@")break;
  cin>>pop;
  //cout<<a_string<<pop<<endl;
  list.createFromBig(a_string,pop);
  }
  list.popTail();
  list.printAll();

  return 0;
}
