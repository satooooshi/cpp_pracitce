#include<iostream>
using namespace std;

class Pencil{
protected://in order to access from subclass "Erasepen"
  int length;
public:
  Pencil(int len):length{len}{}
  void write(){--length;cout<<"length "<<length<<endl;}
};

class Erasepen:public Pencil{
protected:
  int eraser;
public:
  //in order to initialize the base class ":Pencil(arg)"
  Erasepen(int len, int er):Pencil(len),eraser{er}{}
  void erase(){--eraser;cout<<"erase "<<eraser<<endl;}
};

class Colorerasepen:public Erasepen{
  int red;
  int blue;
public:
  Colorerasepen(int r, int b, int len, int er)
    :Erasepen(len,er),red{r},blue{b}{}
};

int main(){

  Colorerasepen *p=new Colorerasepen(5,5,10,3);
  p->write();
  p->write();
  p->erase();
  p->erase();
  p->erase();

return 0;
}
