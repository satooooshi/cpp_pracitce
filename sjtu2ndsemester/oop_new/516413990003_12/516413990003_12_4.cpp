#include<iostream>
using namespace std;

class Vector{
private:
  int *data;
  int size;
public:
  Vector(){size=0;data=new int[0];}
  Vector(int *d, int s){
    size=s;
    data=new int[size];
    for(int i=0;i<size;++i)data[i]=d[i];
  }
  ~Vector(){delete []data;}
  friend void operator+(Vector &v1, Vector &v2);
  friend void operator-(Vector &v1, Vector &v2);
  friend void operator*(Vector &v1, Vector &v2);
  friend istream &operator>>(istream &input, Vector &v);
  friend ostream &operator<<(ostream &output, Vector &v);
  int v_size(){return size;}
  void display();
};

istream &operator>>(istream &input, Vector &v){
  int d[v.size];
  for(int i=0;i<v.size;++i)d[i]=v.data[i];
  delete []v.data;

  v.size+=1;
  int num;
  input>>num;
  v.data=new int[v.size];
  for(int i=0;i<v.size-1;++i)v.data[i]=d[i];
  v.data[v.size-1]=num;

  return input;
}

ostream &operator<<(ostream &output, Vector &v){
  cout<<"{ ";
  if(v.size==0)cout<<"None";
  for(int i=0;i<v.size;++i){
    output<<v.data[i];
    if(i!=v.size-1)cout<<", ";
  }
  cout<<" }";
  return output;
}

void operator+(Vector &v1, Vector &v2){
  int cnt=0;
  if(v1.size>v2.size)cnt=v2.size;
  else cnt=v1.size;
  for(int i=0;i<cnt;++i)v1.data[i]+=v2.data[i];
  return ;
}

void operator-(Vector &v1, Vector &v2){
  int cnt=0;
  if(v1.size>v2.size)cnt=v2.size;
  else cnt=v1.size;
  for(int i=0;i<cnt;++i)v1.data[i]-=v2.data[i];
  return ;
}

void operator*(Vector &v1, Vector &v2){
  int cnt=0;
  if(v1.size>v2.size)cnt=v2.size;
  else cnt=v1.size;
  for(int i=0;i<cnt;++i)v1.data[i]*=v2.data[i];
  return ;
}

void Vector::display(){
  if(size==0)cout<<"None of elements.";
  for(int i=0;i<size;++i)cout<<data[i]<<" ";
  cout<<endl;
  return ;
}

int main(){

  int a[]={1,2,3,4,5,6,7};
  int b[]={3,3,3,3,3,3,3,3,3,3};
  int c[]={};
  int d[10]={};//initialize with 0s;
  Vector v(a,sizeof(a)/sizeof(a[0]));
  Vector vv(b,10);
  Vector vvv(c,0);
  Vector vvvv(d,10);
  vv+v;
  cout<<"------- v --------"<<endl;
  cout<<v.v_size()<<endl;
  cout<<v<<endl;
  cout<<"------- vv -------"<<endl;
  cout<<vv.v_size()<<endl;
  cout<<vv<<endl;
  cout<<"------- vvv ------"<<endl;
  cout<<vvv.v_size()<<endl;
  cout<<vvv<<endl;
  /*
  cout<<"------- vvvv -----"<<endl;
  cout<<"append 2 elements to vvvv: ";
  cin>>vvvv>>vvvv;
  cout<<vvvv.v_size()<<endl;
  cout<<vvvv<<endl;
  */

  return 0;
}
