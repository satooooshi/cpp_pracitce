#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

bool parse(char* array){
  int flag=0;
  while(*array!=0){
    if(*array==32||(*array==35)||(*array==36)||(*array==64)||
       (*array==34)||(*array==44)||(*array==46)||
       ((*array>64)&&(*array<91))||((96<*array)&&(*array<123))||
       ((*array>47)&&(*array<58))){
        ++array;
      }
    else return false;
  }
  return true;
}


void displayNames(char *names){
  while(*names!=0){
    cout<<*names;
    ++names;
  }
  cout<<endl;
}

char* stringToLower(char* string){
  char *tmp=string;//allocated address into tmp
  char *start=tmp;//addressv(this time allocated address of tmp)
  while(*string!=0){//while *string has character
    *tmp=tolower(*string);
    ++tmp;// one character one byte so ++temp
    ++string;
  }
  displayNames(start);
  return start;//return allocated malloc address
}

char* ignoreSpace(char* string){
  char *tmp=string;//allocated address into tmp
  char *start=tmp;//addressv(this time allocated address of tmp)
  while(*string!=0){//while *string has character
    if(*string==' '){++string;continue;}
    *tmp=*string;
    ++tmp;// one character one byte so ++temp
    ++string;
  }
  displayNames(start);
  return start;//return allocated malloc address
}

char* ignoreSign(char* string){
  char *tmp=string;//allocated address into tmp
  char *start=tmp;//addressv(this time allocated address of tmp)
  while(*string!=0){//while *string has character
    if(*string=='@'||*string=='$'||*string=='#'){++string;continue;}
    *tmp=*string;
    ++tmp;// one character one byte so ++temp
    ++string;
  }
  displayNames(start);
  return start;//return allocated malloc address
}


char* removeWord(char* string){
  char *tmp=stringToLower(string);//allocated address into tmp
  char *start=tmp;//addressv(this time allocated address of tmp)
  while(*string!=0){//while *string has character
    if(*string=='l'){string=ignoreSign(string);string=ignoreSpace(string);if(*(string+1)=='4'){string+=2;continue;}}
    if(*string=='f'){string=ignoreSign(string);string=ignoreSpace(string);if(*(string+1)=='d'){string+=2;continue;}}
    if(*string=='d'){
      string=ignoreSign(string);string=ignoreSpace(string);
      if(*(string+1)=='2'){
        string=ignoreSign(string);string=ignoreSpace(string);
        if(*(string+2)=='6'){
          string+=3;continue;
        }
      }
    }
    *tmp=*string;
    ++tmp;// one character one byte so ++temp
    ++string;
  }
  displayNames(start);
  return start;//return allocated malloc address
}


int main(){

cout<<"Please input string > ";
string a_string;
getline (cin,a_string);
char c_style[a_string.size()+1];
strcpy(c_style,a_string.c_str());

//displayNames(c_style,strlen(c_style)+1);
if(parse(c_style)==false){cout<<"Invalid "<<endl;return 0; }
else {
//stringToLower(c_style);
ignoreSpace(c_style);
//ignoreSign(c_style);
//removeWord(c_style);
}








  return 0;
}
