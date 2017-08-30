#include<iostream>
using namespace std;

class Link{
public:
  string value;
  Link(const string& v, Link *p=nullptr, Link *s=nullptr)
    :value{v}, prev{p}, succ{s}{}
  Link* add(Link *n);//insert n after p; return n
  Link* insert(Link *n);//insert n before p; return n
  Link* erase(Link* p);//remove *p and return p's successor
  Link* find(const string& s);
  Link* advance(int n);//move n positions in list, return null for not found
  Link* next()const{return succ;}
  Link* previous()const{return prev;}
  friend void print_all(Link* p);
private:
  Link *prev;
  Link *succ;
};

Link* Link::add(Link *n){
  //if(this==nullptr)return n;//if no node exists
  if(n==nullptr)return this;

  if(succ)succ->prev=n;
  n->prev=this;
  n->succ=succ;
  succ=n;
  return n;
}

//this keyword points to an object for which member functin was called
//ex. object is Link *norse_gods=new Link{"Thor"};
Link* Link::insert(Link *n){//Link *n is new object you want to insert
  //if(this==nullptr)return n;//if no node exists
  if(n==nullptr)return this;

  n->succ=this;
  if(prev)prev->succ=n;
  n->prev=prev;
  prev=n;
  return n;
};

Link* Link::erase(Link* p){
  if(p==nullptr)return nullptr;
  if(p->succ)p->succ->prev=p->prev;
  if(p->prev)p->prev->succ=p->succ;
  return p->succ;
}

Link* Link::find(const string& s){
  Link* p=this;
  while(p){
    if(p->value==s)return p;
    p=p->succ;
  }
  return nullptr;
}

Link* Link::advance(int n){
  Link *p=this;
  if(this==nullptr)return nullptr;
  if(0<n){
    while(n--){
      if(p->succ==nullptr)return nullptr;
      p=p->succ;
    }
  }else if(n<0){
    while(n++){
      if(p->prev==nullptr)return nullptr;
      p=p->prev;
    }
  }
  return p;
}

void print_all(Link *p){
  cout<<"{ ";
  while(p){
    cout<<p->value;
    if(p->succ){cout<<", ";p=p->succ;}
    else break;
  }
  cout<<" }"<<endl;
}

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

  Link *norse_gods=new Link{"Thor"};//the head
  //norse_gods=norse_gods->insert(new Link{"Odin"});
  //norse_gods=norse_gods->insert(new Link{"Feia"});
  //norse_gods=norse_gods->insert(new Link{"Feia"});
  print_all(norse_gods);


}
