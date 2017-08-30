#include<iostream>
#include <fstream>
using namespace std;


void huiwen(string str){
  string str1;
  string str2;
  string maxstring;
  int maxlength=1;

  for(int i=0;i<str.size()-1;i++){
    for(int j=2;j<str.size()-i;j++){
      str1=str.substr(i,j);//str[0(i)]-str[2(j)] -> str[0]-str[3]
      str2=str1;
      reverse(str1.begin(),str1.end());
      if(str2==str1){
        if(str2.size()>maxlength){
          maxlength=str2.size();
          maxstring=str2;
        }
      }
    }
  }
  cout<<"hui wen length : "<<maxlength<<endl;
  cout<<"hui wen : "<<maxstring<<endl;
}

string processLines(string fname){
  char c_style[80];
  ifstream myfile (fname);
  string line;
  string a_string;

  if (myfile.is_open()){
    while ( getline (myfile,line) ){
      //cout<<"line:"<<line<<endl;
      strcpy(c_style,line.c_str());

        for(int i=0;i<strlen(c_style);++i){
            if( (c_style[i]>='A' && c_style[i]<='Z') || (c_style[i]>='a' && c_style[i]<='z')){
              //cout<<c_style[i]<<endl;
              a_string+=c_style[i];
            }
        }
      }
  myfile.close();
  }
  //cout<<"processed : "<<a_string<<endl;
  return a_string;
}


//sizeof(c_style)==80
//strlen(c_style)== actual number of characters in c_style
int main(){
  string cleansed_line;
  string input_filename;//="testtext.txt";
  cout<<"Input filename to read : ";
  getline(cin,input_filename);
  cleansed_line=processLines(input_filename);
  huiwen(cleansed_line);
  return 0;
}
