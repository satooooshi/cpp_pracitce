#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

int shrink_array=0;

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


void displayNames(char *names, int size){
  cout<<"过滤后: ";
  for(int i=0;i<size;++i){
    cout<<names[i];
  }
  cout<<endl;
}


char* ignoreOnlySignAndSpaceUntil(char* string, char c){
  char *start=string;//addressv(this time allocated address of tmp)
  ++string;
  while(*string!=c){//while *string has character

    if((*string!='@')&&(*string!='$')&&(*string!='#')&&(*string!=' ')){
        return start;//return without changing array
    }
    ++string;
  }
  string=start;
  ++string;
  while(*string!=c){
    if((*string=='@')||(*string=='$')||(*string=='#')||(*string==' ')){
        ++string;
        ++shrink_array;
    }
  }
  //cout<<"."<<*string;
  return string;//return changed string address
}


char* removeWord(char* string){
  char *tmp=string;
  char *start=tmp;//addressv(this time allocated address of tmp)
  int still_found=1;
  while(still_found){

  while(*string!=0){//while *string has character
    still_found=0;
    if(tolower(*string)=='l'){string=ignoreOnlySignAndSpaceUntil(string,'4');if(*(string)=='4'){++string;shrink_array+=2;still_found=1;}}
    if(tolower(*string)=='f'){string=ignoreOnlySignAndSpaceUntil(string, 'd');if(tolower(*(string))=='d'){++string;shrink_array+=2;still_found=1;}}
    if(tolower(*string)=='d'){
      string=ignoreOnlySignAndSpaceUntil(string, '2');
      if(*(string)=='2'){
        string=ignoreOnlySignAndSpaceUntil(string, '6');
        if(*(string)=='6'){++string;shrink_array+=3;
          still_found=1;
        }
      }
    }
    *tmp=*string;
    ++tmp;// one character one byte so ++temp
    ++string;
  }
  string=start;
  tmp=start;//addressv(this time allocated address of tmp)

  }
  return start;//return allocated malloc address
}




int main(){
//c++ string -> c style array
cout<<"输入字符串( 没有字符串长度限制 ): ";
string a_string;
getline (cin,a_string);
char c_style[a_string.size()+1];
strcpy(c_style,a_string.c_str());

char final_array[strlen(c_style)+1];

if(parse(c_style)==false){
  cout<<"输入不符合要求"<<endl;return 0;
}else{
  removeWord(c_style);
  displayNames(c_style,strlen(c_style)-shrink_array);
}

return 0;
}
