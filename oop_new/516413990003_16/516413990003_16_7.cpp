#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

vector<string> findPalidrome(string s){
  string forward;
  string backward;
  vector<string>v;
  for(int i=0;i<s.size()-1;++i){//starting word of palindrome
    for(int j=i;j<s.size();++j){//length of palindrome
      forward+=s[j];
      //cout<<forward<<endl;
      for(int x=forward.size()-1;x>=0;--x){
      backward+=forward[x];
      //cout<<"     "<<backward<<endl;
      }
      if(forward==backward&&forward.size()>=2)v.push_back(backward);
      backward="";
      if(j==2001)break;
    }
    forward="";
  }
  return v;
}

string ifStream(string s){
ifstream ifs (s, std::ifstream::in);
int dig=0;
int alph=0;
int other=0;
int cnt=0;
if(!ifs)throw -1;
 char c;
 string str;
 while (ifs>>c) {
   ++cnt;
   if(isalpha(c)){
     ++alph;
     str+=c;
   }else if(isdigit(c))++dig;
   else ++other;

 }
 ifs.close();
 //cout<<"The total number of alphabet is : "<<alph<<endl;
 //cout<<"The total number of digit is : "<<dig<<endl;
 //cout<<"The total number of other latter : "<<other<<endl;
 //cout<<"The total number of latter is : "<<cnt<<endl;
 return str;
}



int main(){

try{

vector<string>data=findPalidrome(ifStream("palindrome.in"));

int maxlen=2;
vector<string>longest;

for(int i=0;i<data.size();++i){
  if(data[i].size()>=maxlen){
    maxlen=data[i].size();
  }
}
for(int i=0;i<data.size();++i){
  if(data[i].size()==maxlen)
  longest.push_back(data[i]);
}

std::ofstream ofs ("palindrome.out",std::ofstream::out);
if(!ofs)throw -1;
for(int i=0;i<longest.size();++i)ofs<<longest[i]<<endl;
ofs.close();

}catch(int i){
  cerr<<"ERROR : The file does not exist."<<endl;
}

  return 0;
}
