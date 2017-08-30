#include<iostream>
using namespace std;

char *mystrrchr(char *str, char ch){
int pos=-1;
  for(int i=0;i<strlen(str);++i){
    if(ch==str[i])pos=i;
  }
//cout<<"strlen"<<strlen(str)<<endl;
//cout<<"str+pos"<<str[pos]<<endl;
  if(pos>=0)return str+pos;
  else return NULL;
}

int main(){

  cout<<"Please input string > ";
  string a_string;
  getline (cin,a_string);
  char c_style[a_string.size()+1];
  strcpy(c_style,a_string.c_str());

  char c;
  cout<<"input a character > ";
  cin>>c;

  if(mystrrchr(c_style, c)!=NULL)cout<<mystrrchr(c_style,c)<<endl;
  else cout<<"Character '"<<c<<"' not exist in this string."<<endl;

  return 0;
}
