// swapping ostringstream objects
//#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>      // std::stringstream

#include <fstream>      // std::ifstream

using namespace std;


void ifStream(){
ifstream ifs ("testtext.txt", std::ifstream::in);
 char c = ifs.get();
 //while(ifs>>c){//doen not separate, doesnt read space and endofline
 while (ifs.good()) {
   cout << c;
   c = ifs.get();//identical to inputfile format
 }
 ifs.close();
}

void stringStream(){
  stringstream ss;
  ss << 100 << ' ' << 200;
  int foo,bar;
  ss >> foo >> bar;
  cout << "foo: " << foo << '\n';
  cout << "bar: " << bar << '\n';
}

void ofStream(){
  std::ofstream ofs ("testtext.txt",std::ofstream::out | std::ofstream::app);
  //std::ofstream::app -->append
  //std::ofstream::trunc--> clean file
  ofs << "lorem ipsum"<<endl;
  ofs.close();
}

void conversion(){
  //c++ to c style string
    cout<<"Please input string > ";
    string a_string;
    //cin>>a_string;//separated by space<==========
    getline (cin,a_string);//get by line (space allowed)<==========
    char c_style[a_string.size()];
    cout<<"The number of input characters : "<<a_string.size()<<endl;
    strcpy(c_style,a_string.c_str());
    cout<<c_style<<endl;//aikawasatoshi
    cout<<c_style[2]<<endl;//k
    cout<<c_style+2<<endl;//kawasatoshi

  //c style to c++
    a_string=c_style;//dont need to use [] and forloop
    cout<<"C++ style string : "<<a_string<<endl;
}

void word_cnt(const char *s){
  int cnt=0;
  cout<<"word count in string ' "<<s<<" ' : ";//need not for loop and [i]

  while(*s!='\0'){
    while(*s==' ')++s;
    if(*s!='\0'){
      ++cnt;
      while(*s!=' '&&*s!='\0')++s;
    }
  }
  cout<<cnt<<endl;
  return ;
}

int main(){

//stream

  ifStream();
/*  cout<<endl;
  stringStream();
  cout<<endl;
  ofStream();
  cout<<endl;
  ifStream();
*/

//c++ <-> c
  //conversion();

//word conunt
  //char str[]="  aikawa satoshi ";//char *str warning!!
  //word_cnt(str);


  return 0;
}
