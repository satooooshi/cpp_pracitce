#include<iostream>
#include<fstream>

class Haha{
private:
  int x;
public:
  Haha(int a){x=a;}
  int get_data(){return x;}
  //dont forget';''!!
  //friend enables this func to access private: int x
  friend std::ostream &operator<<(std::ostream &output, Haha &haha);
};


std::ostream &operator<<(std::ostream &output, Haha &haha){
  output<<haha.get_data(); return output;
}//return type std::ostream, << means output operator
 //const Haha &haha cant compile!!
 //should be contained in class with friend!!


int main(){

Haha h(5);

//dont forget to #include<fstream>
std::ofstream out_ha("out_ha.txt");

out_ha<<h<<std::endl;

  return 0;
}
