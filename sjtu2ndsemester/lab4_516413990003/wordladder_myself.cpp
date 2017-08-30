#include<iostream>
#include<queue>
#include<vector>
#include<fstream>
#include<unordered_set>
#include<stack>
using namespace std;

class Lexicon{
  unordered_set<string>dict;
  string start;
  string end;
public:
  Lexicon(string str,string st,string en);
  void wordLadder();
  bool findNextWord(queue<stack<string>>&q, stack<string>&sta, string current_word);
};

Lexicon::Lexicon(string str,string st, string en){
  start=st;
  end=en;
  ifstream ifs(str);
  string word;
  while(ifs>>word){
    dict.insert(word);
  }
  wordLadder();
}

bool Lexicon::findNextWord(queue<stack<string>>&q, stack<string>&sta, string current_word){

  int n = current_word.length();
  string temp = current_word;
  stack<string>copy_sta;
  for (int p = 0; p < n; p++) {
      for (int i = 0; i < 26; i++) {
          current_word[p] = 'a' + i;
          if(dict.find(current_word)!=dict.end()){
            if(current_word==end){
              sta.push(current_word);
              while(!sta.empty()){
                cout<<sta.top()<<" "<<endl;
                sta.pop();
              }
              return true;
            }else{
              copy_sta=sta;
              copy_sta.push(current_word);
              dict.erase(current_word);
              q.push(copy_sta);
            }
          }
      }
      current_word=temp;
  }
  return false;
}

void Lexicon::wordLadder(){

  queue<stack<string>>que;
  stack<string>sta;
  sta.push(start);
  que.push(sta);

  while(!que.empty()){
    stack<string>current_stack=que.front();
    string current_word=que.front().top();
    que.pop();
    if(findNextWord(que,current_stack,current_word)==true)
      return ;
  }

}


int main(){

  Lexicon l("dictionary.txt","toxic","elite");

  return 0;
}
