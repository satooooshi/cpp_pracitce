//******************************************
//516413990003
//会川慧
//
//******************************************


#include<iostream>
#include<queue>
#include<set>
#include<vector>
#include<unordered_set>//集合
#include<unordered_map>//マップ関連付け
#include<fstream>
using namespace std;


class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string> > ladders;
        vector<string> ladder;
        ladder.push_back(start);
        unordered_set<string> startWords, endWords;
        startWords.insert(start);
        endWords.insert(end);
        unordered_map<string, vector<string> > children;
        bool flip = true;//for output
        if (searchLadders(startWords, endWords, dict, children, flip))
            genLadders(start, end, children, ladder, ladders);
        return ladders;
    }
private:
    bool searchLadders(unordered_set<string>& startWords, unordered_set<string>& endWords,
                 unordered_set<string>& dict, unordered_map<string, vector<string> >& children, bool flip) {
        flip = !flip;
        if (startWords.empty()) return false;
        if (startWords.size() > endWords.size())
            return searchLadders(endWords, startWords, dict, children, flip);
        for (string word : startWords) dict.erase(word);
        for (string word : endWords) dict.erase(word);
        unordered_set<string> intermediate;
        bool done = false;
        for (string word : startWords) {
            int n = word.length();
            string temp = word;//buffer, evacuate original word
            for (int p = 0; p < n; p++) {
                char letter = word[p];
                for (int i = 0; i < 26; i++) {
                    word[p] = 'a' + i;
                    if (endWords.find(word) != endWords.end()) {
                      //if endWords.find() cant find then return end()
                      //found  word(one latter different) the same with endword
                        done = true;
						flip ? children[word].push_back(temp) : children[temp].push_back(word);
                      //push temp to word(one latter different)
                      //OR
                      //the other way around
                    }
                    else if (!done && dict.find(word) != dict.end()) {
                      //ここでメインのラダーを作る
                      //found word(one latter different) in dictionary
                        intermediate.insert(word);//これを成長させていく2
						flip ? children[word].push_back(temp) : children[temp].push_back(word);
                    //put word(one word different) after temp
                    }
                }
                word[p] = letter;
            }
        }
        return done || searchLadders(endWords, intermediate, dict, children, flip);
        //if(false) then coudnt found or start words not correct
    }

    void genLadders(string& start, string& end, unordered_map<string, vector<string> >& children,
                    vector<string>& ladder, vector<vector<string> >& ladders) {
        if (start == end) {
            ladders.push_back(ladder);
            return;
        }
        for (string child : children[start]) {
            ladder.push_back(child);
            genLadders(child, end, children, ladder, ladders);
            ladder.pop_back();
        }
    }
};


int main(){

  try{

  Solution s;

//input
//------------------------------------------------------------------------------
  string name;
  string str;
  string sa;
  string sb;

  cout<<"Dictionary file name? ";
  getline(cin,name);
  ifstream ifs (name, std::ifstream::in);
  if(!ifs)throw string("The file does not exist.");
  unordered_set<string>data;
  while (ifs>>str){
    data.insert(str);
  }
  ifs.close();

  while(true){
  cout<<"Word #1 (or Enter to quit): ";
  getline(cin,sa);
  if(sa[0]=='\0')throw string("Have a nice day.");
  for(int i=0;i<sa.size();++i){
  if(!isalpha(sa[i]))throw string("Only alphabets are acceptable.");
  sa[i]=tolower(sa[i]);
  }
  if(data.find(sa) == data.end())throw string(sa+" not found in "+name);
  cout<<"Word #2 (or Enter to quit): ";
  getline(cin,sb);
  if(sb[0]=='\0')throw string("Have a nice day.");
  for(int i=0;i<sb.size();++i){
  if(!isalpha(sb[i]))throw string("Only alphabets are acceptable.");
  sb[i]=tolower(sb[i]);
  }
  if(data.find(sb) == data.end())throw string(sb+" not found in "+name);
  if(sa==sb)throw string("The two words must be different.");
  if(sa.length()!=sb.length())throw string("The two words must be the same length.");
//------------------------------------------------------------------------------

  vector<vector<string>>vec;//vector of vector
  vec=s.findLadders(sa,sb,data);

//output
//------------------------------------------------------------------------------
  if(!vec.size())cout<<"No word ladder found from "<<sb<<" back to "<<sa<<".";
  else
  cout<<"A ladder from "<<sa<<" to "<<sb<<":"<<endl;
  for (int i = 0; i < vec.size(); i++)
  {   cout<<"{ ";
      for (int j = vec[i].size()-1; j >=0 ; --j)
      {
          cout << vec[i][j]<<" ";
        }
        cout<<"}"<<endl;
      }
    }
//------------------------------------------------------------------------------

}catch(string e){
  cerr<<e<<endl;
  return 0;
}

  return 0;
}
