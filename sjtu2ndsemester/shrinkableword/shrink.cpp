#include<iostream>
#include<fstream>
#include<vector>
#include<unordered_set>
using namespace std;


class Lexicon{
  unordered_set<string>dict;
public:
  Lexicon(string str);
  bool shrinkable(string &word);
};

Lexicon::Lexicon(string str){
  ifstream ifs(str);
  string word;
  while(ifs>>word){
    dict.insert(word);
  }
}

bool Lexicon::shrinkable(string &word){
  if(dict.find(word)==dict.end())return false;
  //cout<<word<<endl;
  if(word.length()==1)return true;//base condition
  for(int i=0;i<word.length();++i){
    string shwd=word.substr(0,i)+word.substr(i+1);
    if(shrinkable(shwd)){
      return true;
    }
  }
  return false;
}


int main(){

Lexicon dict("dictionary.txt");
string word="startling";
cout<<dict.shrinkable(word)<<endl;
/*
string shwd;
string word="aiueo";
for(int i=1;i<word.length();++i){
shwd=word.substr(0,i)+word.substr(i+1);
cout<<shwd<<endl;
}
*/
  return 0;
}
