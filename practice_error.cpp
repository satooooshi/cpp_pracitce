#include<iostream>
using namespace std;
/*
int main () {
  try
  {
    throw 20;//int 20
  }
  catch (int e)// because  20 is int
  {
    cout << "An exception occurred. Exception Nr. " << e << '\n';
  }
  return 0;

}
*/

class Bad_area{
  public:
  int value;
};

int area(int width, int length){
  if(length<=0 || width<=0)throw Bad_area{width};//Bad_area.value=-1
//Bad_area{} means "make an object of type Bad_area with default value"
  return length*width;
}

int main(){
  try{
    //int x=-1 means "make an object x of type int with default -1"
    int x=-1;//int-class, x-object
    int y=2;
    int z=4;

    int area1=area(x,y);

  }catch(Bad_area a){//Bad_area is a type, a is a object
    cout<<"Oops Bad_area! : "<<a.value<<"\n";
  }
}



/*
class Bad_argument{
  public:
    int value;
};

int main() {
	int i;
	cout << "0 or 1 > ";
	cin >> i;

	try {
    if (i) throw 100;
		else throw Bad_argument{-1};//Bad_argument.value=-1
	}
	catch (Bad_argument b) { cout << "Exception : " << b.value << '\n'; }
	catch (int e) { cout << "Exception : " << e << '\n'; }
  catch (...){cout<<"Exeption: Unknown type\n"; }
	return 0;
}
*/
