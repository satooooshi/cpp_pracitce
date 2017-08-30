#include<iostream>
#include<memory>
#include<vector>
using namespace std;

class Node{
public:
  int value;
  shared_ptr<Node>next;
  Node(){}
  Node(int v):value(v){}
};

class List{
private:
  shared_ptr<Node>head;
  shared_ptr<Node>tail;
  shared_ptr<Node>current;//act as a buffer
  int size;
public:
  List(const vector<int>& v);
  List(int *array, int array_size);
  ~List(){};
  int length()const{return size;}
  int find(int value);
  bool insert(int pos, int value);
  int remove(int value);
  void combine(List &append_list);
  bool split(int pos, List &new_list);
  void printAll();
};

List::List(const vector<int>& v)
  :size((int)v.size()),head(NULL),tail(NULL),current(NULL)
  {
    if(size!=0){
    head=shared_ptr<Node>(new Node(v[0]));//first elememt
    tail=head;
    tail->next=NULL;
    current=head;
    for(int i=1;i<size;++i){
      current=shared_ptr<Node>(new Node(v[i]));
      current->next=head;
      head=current;
    }
    }
  }

List::List(int *array, int array_size)
  :size(array_size),head(NULL),tail(NULL),current(NULL)
  {
    if(size!=0){
    head=shared_ptr<Node>(new Node(array[0]));//first element
    tail=head;
    tail->next=NULL;
    current=head;
    for(int i=1;i<array_size;++i){
      current=shared_ptr<Node>(new Node(array[i]));
      current->next=head;
      head=current;
    }
    }
  }


int List::find(int value){
  int pos=-1;
  int i=0;
  current=head;
  while(current!=NULL){
    if(current->value==value){pos=(size-1)-i;}//array start from 0
    //if(current->next==NULL)break;
    current=current->next;
    //cout<<"i"<<current->value<<endl;
    ++i;
  }
  if(pos>=0)return pos;
  else return -1;
}

bool List::insert(int pos, int value){
  if(pos>length()||pos<0)return false;
  current=head;
  for(int i=0;i<size-pos-1;i++)current=current->next;
  shared_ptr<Node> new_node (new Node(value));
  if(pos<length()){
  new_node->next=current->next;
  current->next=new_node;
  }else if(pos==length()){
    new_node->next=head;
    head=new_node;
  }
  ++size;
  return true;
}

int List::remove(int value){
  int del=0;
  shared_ptr<Node> pre_node (new Node);
  current=head;
  pre_node=current;
  while(current!=NULL){
    if(current->value==value){
      ++del;
      --size;
      if(current==head){//remove head
        current=current->next;
        head=current;
        pre_node=current;
        continue;
      }else{            //remove non head
        pre_node->next=current->next;
        current=current->next;
        continue;
      }
    }
    pre_node=current;
    current=current->next;
  }
  return del;
}

void List::combine(List &append_list){
  if(append_list.tail==NULL)return ;
  append_list.tail->next=head;
  head=append_list.head;
  size+=append_list.size;
}

bool List::split(int pos, List &new_list){
  if(pos>=length()||pos<0){return false;}
  current=head;
  shared_ptr<Node>pre_node=current;
  for(int i=(size-1)-pos;i>0;--i){
    pre_node=current;
    current=current->next;
  }
  //add splitted elems to new_list
  pre_node->next=new_list.head;
  new_list.head=head;
  head=current;

  new_list.size+=(size-pos-1);
  size-=(size-pos-1);//delete splitted elems from list
  if(new_list.size==1)new_list.tail=new_list.head;
  return true;
}

void List::printAll(){
    int v[size];
    int i=0;
    current=head;
    while(current!=NULL){
      v[i]=current->value;
      current=current->next;
      ++i;
    }
    for(int i=size-1;i>=0;--i)cout<<v[i]<<" ";
    cout<<endl;
}
