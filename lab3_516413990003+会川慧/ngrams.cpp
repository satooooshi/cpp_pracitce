//******************************************
//516413990003
//会川慧
//
//------------EXTRA features---------------
//Make the N-grams be complete sentences
//related code located at line 28,32,104,108
//******************************************


#include<iostream>
#include<fstream>
#include<vector>
#include <map>
#include <random>
using namespace std;

class Ngram{
private:
  int N;
  int LENGTH;
  vector<string>lexi;//Lexicon
  vector<string>data;//sentence buffer
  map<vector<string>,vector<string>> m;
  bool dot;
  void generateMap();
  void generateSentence(string sentence="", int cnt=0);//no argument required
  void displayMap();//display map{prefixes}:{suffixes}
  inline bool findUpper(string s){
    char c=s[0];
    return isupper(c);
  }
  inline bool findFin(string s){
    if(s[s.size()-2]=='.')return true;//sentence+=" " == always end with 'space'
    else if(s[s.size()-2]=='!')return true;
    else if(s[s.size()-2]=='?')return true;
    else return false;
  }
  inline int dice(int x){
    random_device rd;
    return rd() % x + 1 - 1;//range from 0 to x
  }
public:
  Ngram();
};

Ngram::Ngram(){
  dot=false;
  string name("");
  double n=0;
  double len=0;
  N=0;
  LENGTH=0;

  cout<<"Input file? ";
  cin>>name;
  ifstream ifs(name, std::ifstream::in);
  if(!ifs)throw string("The file does not exist.");
  string s;
  while(ifs>>s)lexi.push_back(s);
  ifs.close();
 // for(string str:lexi)cout<<str<<endl;
 for(string a:lexi){
   if(a[a.size()-1]=='.'||a[a.size()-1]=='?'||a[a.size()-1]=='!'){
     dot=true;
     break;
   }
   dot=false;
 }

  cout<<"Value of N? ";
  cin>>n;
  if(n<3||n>50)throw string("Unacceptable input.");
  if(n-(int)n!=0)throw string("Only integer is acceptable.");
  N=(int)n;

  generateMap();

  while(true){
    cout<<endl<<"# of random words to generate (0 to quit)? ";
    cin>>len;
    if(len-(int)len!=0)throw string("Only integer is acceptable.");
    if(len==0){cout<<"Exiting"<<endl;return ;}
    if(len<=N)throw string("# should be greater than the value of N.");
    if(len>lexi.size())throw string("# is bigger than the # of words in this input file.");
    LENGTH=(int)len;
    generateSentence();
    data.clear();
  }

}

void Ngram::generateMap(){
  vector<string>right;//suffixes
  vector<string>left;//prefixes
  pair<map<vector<string>,vector<string>>::iterator,bool> ret;
  int j=0;
  while(j<lexi.size()-(N-1)){
    for(int x=0;x<N-1;++x){left.push_back(lexi[j]);++j;}//for N-1 loop
    right.push_back(lexi[j]);
    ret = m.insert (pair<vector<string>,vector<string>>(left,right));
    if (ret.second==false){
      ret.first->second.push_back(lexi[j]);//already mapped
    }
    j=j-(N-2);
    right.clear();
    left.clear();
  }
  //displayMap();/display map{prefixes}:{suffixes}
}

void Ngram::generateSentence(string sentence, int cnt){
  if(dot){
    if( (cnt>=LENGTH-N)&&findFin(sentence)){ cout<<sentence<<endl;return ;}
  }else{
    if( (cnt>=LENGTH-N)){ cout<<sentence<<"..."<<endl;return ;}//for text with no dots
  }
  if(cnt==0){
    map<vector<string>,vector<string>>::iterator it = m.begin();
    advance( it, dice(m.size()) );//random start point
    while(!findUpper(it->first[0])){//Cased latter for the head of sentence.
      it=m.begin();
      advance( it, dice(m.size()) );
    }
    for(int i=0;i<it->first.size();++i){//output prefixes
      sentence+=it->first[i];
      sentence+=" ";
      data.push_back(it->first[i]);
    }
    sentence+=it->second[dice(it->second.size())];//choose frequent elem
    sentence+=" ";                                //output suffixes
    data.push_back(it->second[dice(it->second.size())]);
    data.erase (data.begin());//delete the first prefixes to creating new prefixes
  }

      map<vector<string>,vector<string>>::iterator it = m.begin();
      for (it=m.begin(); it!=m.end(); ++it){

        if(data==it->first){//*********map.find()==data -> add suffixes to sentence
          sentence+=it->second[dice(it->second.size())];//second[1] or second[2] or.....
          sentence+=" ";
          data.push_back(it->second[dice(it->second.size())]);
          data.erase (data.begin());
          break;
        }
      }

  return generateSentence(sentence, ++cnt);//loop for the number of words
}

void Ngram::displayMap(){

  map<vector<string>,vector<string>>::iterator it = m.begin();

  for (it=m.begin(); it!=m.end(); ++it){
  cout <<"{ ";
    for(int i=0;i<it->first.size();++i){//'the number of prefixes' times loop
      cout<< it->first[i]<<", ";
    }
    cout<<"} : { ";
    for(int i=0;i<it->second.size();++i){
      cout<< it->second[i]<<", ";
    }
    cout<<" }"<< endl;
  }
}


int main(){

try{
  Ngram n;
}catch(string s){
    cerr<<s<<endl;
    return 0;
}
  return 0;
}
