#include<iostream>
#include<vector>
#include<fstream>
using namespace std;


//start, finish, temp sticks
void hanoi(int n, char start, char finish, char temp){
  if(n==1)cout<<start<<"->"<<finish<<endl;
  else{
    hanoi(n-1,start,temp,finish);
    cout<<start<<"->"<<finish<<endl;
    hanoi(n-1,temp,finish,start);
  }
}



vector<string>v;

class Lexicon {
private:
  vector<string>word;
public:
  Lexicon(const string str);
  bool contains(const string str)const;
};

Lexicon::Lexicon(const string str){
  ifstream ist{str};
  string s;
  while (getline(ist, s)){
    word.push_back(s);
  }
  ist.close();
}

bool Lexicon::contains(const string str)const{
  for(string s:word)
    if(s==str)
      return true;
  return false;
}
//substr(pos,len)
bool isShrinkable(const string& word, const Lexicon& english) {
if (!english.contains(word)) return false;
//if (english.contains(word)){v.push_back(word);}
if (word.length() == 1) return true;
for (int i = 0; i < word.length(); i++) {
  string shrunken = word.substr(0, i) + word.substr(i + 1);
  //cout<<shrunken<<endl;
  if (isShrinkable(shrunken, english)) {//when word.lengh()==1 then true
    return true;                 //exit function
  }
}
return false;
}

int main(){

  const Lexicon dic("smalldict1.txt");
  isShrinkable("here",dic);

  for(string s:v)cout<<s<<" "<<endl;

  return 0;
}
