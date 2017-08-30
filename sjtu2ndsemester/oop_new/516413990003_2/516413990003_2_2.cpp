#include<iostream>
using namespace std;

int main(){

  char word;

  cout<<"请输入一个字母:";
  cin>>word;

if(word>='a'&& word<='z'){

  switch(word){
    case 'a':
    case 'i':
    case 'u':
    case 'e':
    case 'o':
      cout<<"元音\n";
      break;
    default:
      cout<<"辅音\n";
    }
  }else{
      cout<<"不是英文字母\n";
  }
  
  return 0;
}
