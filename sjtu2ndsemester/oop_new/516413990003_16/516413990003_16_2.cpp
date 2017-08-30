#include<iostream>
#include<fstream>
using namespace std;

void ifStream(string s){
ifstream ifs (s, std::ifstream::in);
int dig=0;
int alph=0;
int other=0;
int cnt=0;
if(!ifs)throw -1;
 char c;
 while (ifs>>c) {
   ++cnt;
   if(isalpha(c))++alph;
   else if(isdigit(c))++dig;
   else ++other;
 }
 ifs.close();
 cout<<"The total number of alphabet is : "<<alph<<endl;
 cout<<"The total number of digit is : "<<dig<<endl;
 cout<<"The total number of the other latter : "<<other<<endl;
 cout<<"The total number of latter is : "<<cnt<<endl;
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
