#include<iostream>
#include<vector>//vector
#include <algorithm>//sort()

using namespace std;

int main(){
//c++ to c style string
  cout<<"Please input string > ";
  string a_string;
  //cin>>a_string;//separated by space
  getline (cin,a_string);//get by line
  getline (cin,a_string);
  char c_style[a_string.size()+1];
  strcpy(c_style,a_string.c_str());

//vector<int> v={1, 2, 3, 4, 5, 6, 7};
//vector<int> v{1, 2, 3, 4, 5, 6, 7};
//for(int x : v)
//    cout<<x<<"\n";

//vector<int>v;
//int temp;
//while((cin>>temp) && (temp!='q')){
//  v.push_back(temp);
//}
//for(int x:v)
//  cout<<x<<"\n";

/*
vector<string>v;
for(string s;cin>>s && s!="quit";)
  v.push_back(s);
sort(v.begin(),v.end());
for(string s: v)
  cout<<s<<"\n";
cout<<"The number of v:"<<v.size()<<'\n';
*/

/*
//n times input -> sort -> output
int n=0;
int temp=0;
int i=0;
vector<int> v;
cin>>n;
for(i=0;i<n;++i){
  cin>>temp;
  v.push_back(temp);
}
sort(v.begin(),v.end());
for(int temp : v)
  cout<<temp<<'\n';
*/

vector<int>v(5);//create an vector with default value {0,0,0,0,0}
for(int i=1;i<=5;++i)v.push_back(i);
for(int x:v)cout<<x<<" "<<endl;



  return 0;
}
