//name_of_your_list_header_file.h

#include<iostream>
using namespace std;
#include<vector>
#include<cstdlib>

class Node{
public:
  int value;
  Node *next;
  Node(int v):value(v),next(NULL){}
};

class List{
private:
  int size;
  Node *head;
  Node *first;
  bool combined;
public:
  List(const vector<int>& v)
    :size((int)v.size()),head(NULL),combined(false)
    {
      first=head;
      Node *cur_node=head;
      for(int i=0;i<size;++i){
        head=new Node(v[i]);
        head->next=cur_node;
        cur_node=head;
      }
    }

  List(int *array, int array_size)
    :size(array_size),head(NULL), combined(false)
    {
      first=head;
      Node *cur_node=head;
      for(int i=0;i<size;++i){
        head=new Node(array[i]);
        head->next=cur_node;
        cur_node=head;
      }
    }

  ~List()
  {
    if(!combined){
      Node *cur_node=head;
      while(true){
        delete[] cur_node;
        head=head->next;
        cur_node=head;
        if(head->next==NULL){delete[] head; break;}
      }
    }
  }

  int length()const{return size;}

  bool insert(int pos, int value)
    {
      if(pos<length())
      {
        Node *new_node=new Node(value);
        Node *cur_node=head;
        for(int i=0;i<(size-pos)-1;++i){cur_node=cur_node->next;}
        new_node->next=cur_node->next;
        cur_node->next=new_node;
        ++size;
        return true;
      }else if(pos==length()){
        Node *new_node=new Node(value);
        new_node->next=head;
        head=new_node;
        ++size;
        return true;
      }else{
        return false;
      }
    }

  int remove(int value){

   int del=0;
   Node *cur_node=head;
   Node *pre_node=head;
   while(cur_node){
      if(cur_node->value==value){
        if(cur_node==head){
          ++del;
          --size;
          head=cur_node->next;
          delete[] cur_node;
          cur_node=head;
        }else{
          ++del;
          --size;
          pre_node->next=cur_node->next;
          delete[] cur_node;
          cur_node=pre_node;
        }
      }
      pre_node=cur_node;
      cur_node=cur_node->next;
    }
    return del;

  }

  void combine(List &append_list){
    append_list.combined=true;
    Node *append_list_first=append_list.head;
    while(true){
      append_list_first=append_list_first->next;
      if(append_list_first->next==NULL){break;}
    }
    append_list_first->next=head;
    head=append_list.head;
    size+=append_list.size;
  }

  bool split(int pos, List &new_list){
   if(pos<size){

    Node *cur_node=head;
    int i=0;
    for(int i=0;i<size-pos-2;++i){
      cur_node=cur_node->next;
    }
    Node *last_before_splitted=cur_node->next;
    Node *splitted_node_first=cur_node;
    splitted_node_first->next=new_list.head;
    new_list.head=head;
    head=last_before_splitted;
    size-=pos;
    new_list.size+=pos;
    return true;

   }else{
     return false;
   }

  }

  int find(int value){
    Node *cur_node=head;
    int arr[size];
    int i=0;
    for(int i=0;i<size;++i){
      arr[i]=cur_node->value;
      cur_node=cur_node->next;
    }
    for(int i=size-1;i>=0;--i){
      if(arr[i]==value)return (size-i);
    }
    return -1;
  }

void printAll(){
  Node *cur_node=head;
  int arr[size];
  int i=0;
  for(int i=0;i<size;++i){
    arr[i]=cur_node->value;
    cur_node=cur_node->next;
  }
  for(int i=size-1;i>=0;--i)cout<<arr[i]<<" ";
  cout<<endl;
}
};
