#include<iostream>
#include<fstream>
using namespace std;


void ifStream(string s){
ifstream ifs (s, std::ifstream::in);
if(!ifs)throw -1;
 char c = ifs.get();
 while (ifs.good()) {
   cout << c;
   c = ifs.get();//identical to inputfile format
 }
 ifs.close();
}

int main(){

string name;
cout<<"Enter a file name : ";
cin>>name;

try{
ifStream(name);
}catch(int i){
  cerr<<"ERROR : The file does not exist."<<endl;
}

  return 0;
}
