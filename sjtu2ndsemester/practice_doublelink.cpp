#include<iostream>
using namespace std;

class Node{
public:
  string value;
  Node(const string &s):value{s}{}
};


class Link{
public:
  Node node;
  Link(Node *n)
    :head{n}{}
private:
  Link *prev;
  Link *succ;
  Link *head;
  Link *tail;
};


int main(){

  /*
  Link *norse_gods=new Link{"Thor",nullptr,nullptr};//the head
  cout<<"address at Thor node -> "<<norse_gods<<endl;
  norse_gods=new Link{"Odin",nullptr,norse_gods};
  cout<<"address at Odin node ->"<<norse_gods<<endl;
  norse_gods->succ->prev=norse_gods;
  norse_gods=new Link{"Freia",nullptr,norse_gods};
  cout<<"address at Odin node ->"<<norse_gods<<endl;
  norse_gods->succ->prev=norse_gods;
  */

  Link norse_gods{Node{"Thor"}};//the head
  //norse_gods.add(Link{"Odin"});
  //print_all(norse_gods);


}
