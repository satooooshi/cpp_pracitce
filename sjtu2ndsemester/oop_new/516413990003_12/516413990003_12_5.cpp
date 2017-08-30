#include<iostream>
#include<string>
using namespace std;

class String{
private:
  char *data;
  int size;
public:
  String(){size=0;data=new char[0];}
  String(char s[]);
  ~String(){delete []data;}
  int str_size(){return size;}
  String operator=(const String &s);
  friend istream &operator>>(istream &input, String &s);
  friend ostream &operator<<(ostream &output, String &s);
  friend int operator>(const String &s1, const String &s2);
  friend int operator<(const String &s1, const String &s2);
  friend int operator>=(const String &s1, const String &s2);
  friend int operator<=(const String &s1, const String &s2);
  friend String operator+(String &s1, String &s2);
  friend void operator+=(String &s1, String &s2);
  friend bool operator==(String &s1, String &s2);
  friend bool operator!=(String &s1, String &s2);

};

String::String(char s[]){
    size=strlen(s);
    data=new char[size];
    //data=s;-> put address of s into data; cant do it!!
    for(int i=0;i<size;++i)data[i]=s[i];
    //cout<<"size"<<size<<endl;
    //cout<<data<<endl;
  }

String String::operator=(const String &s){
  size=s.size;
  data=new char[size];
  strcpy(data,s.data);
  return this->data;//this constains just address
}



istream &operator>>(istream &input, String &s){
  string str;
  //input>>str;//cant contain space
  getline(input,str);
  s.size=str.size();
  s.data=new char[s.size];
  strcpy(s.data,str.c_str());
  return input;
}

ostream &operator<<(ostream &output, String &s){
  output<<s.data;
  return output;
}

String operator+(String &s1, String &s2){
  char *c=s1.data;
  s1.size=s1.size+s2.size;
  delete[] s1.data;
  s1.data=new char[s1.size];
  strcpy(s1.data,c);
  strcat(s1.data,s2.data);
  return s1.data;
}

void operator+=(String &s1, String &s2){
  char *c=s1.data;
  s1.size=s1.size+s2.size;
  delete[] s1.data;
  s1.data=new char[s1.size];
  strcpy(s1.data,c);
  strcat(s1.data,s2.data);
  return ;
}

bool operator==(String &s1, String &s2){
  if(s1.size!=s2.size)return false;
  for(int i=0;i<s1.size;++i){
    if(s1.data[i]!=s2.data[i])return false;
  }
  return true;
}

bool operator!=(String &s1, String &s2){
  if(s1.size!=s2.size)return true;
  for(int i=0;i<s1.size;++i){
    if(s1.data[i]!=s2.data[i])return true;
  }
  return false;
}

int operator>(const String &s1, const String &s2){
  int cnt=0;
  if(s1.size>s2.size)cnt=s2.size;
  else cnt=s1.size;
  for(int i=0;i<cnt;++i){
    if(s1.data[i]>s1.data[i])
      return 1;
    else if(s1.data[i]<s2.data[i])
      return -1;
  }
  return 0;
}

int operator<(const String &s1, const String &s2){
  int cnt=0;
  if(s1.size>s2.size)cnt=s2.size;
  else cnt=s1.size;
  for(int i=0;i<cnt;++i){
    if(s1.data[i]>s1.data[i])
      return -1;
    else if(s1.data[i]<s2.data[i])
      return 1;
  }
  return 0;
}

int operator>=(const String &s1, const String &s2){
  int cnt=0;
  if(s1.size>s2.size)cnt=s2.size;
  else cnt=s1.size;
  for(int i=0;i<cnt;++i){
    if(s1.data[i]>s1.data[i])
      return 1;
    else if(s1.data[i]<s2.data[i])
      return 0;
  }
  return 1;
}

int operator<=(const String &s1, const String &s2){
  int cnt=0;
  if(s1.size>s2.size)cnt=s2.size;
  else cnt=s1.size;
  for(int i=0;i<cnt;++i){
    if(s1.data[i]>s1.data[i])
      return 0;
    else if(s1.data[i]<s2.data[i])
      return 1;
  }
  return 1;
}





  int main(){

    char a[]="This ";
    char b[]="apple ";
    char c[]="is ";
    char d[]="mine.";
    String s(a);
    String ss(b);
    String sss(c);
    String ssss(d);
    String sssss;
    cout<<(s>ss)<<endl;
    cout<<(s<ss)<<endl;
    cout<<(s>=ss)<<endl;
    cout<<(s<=ss)<<endl;
    cout<<(s==ss)<<endl;
    cout<<(s!=ss)<<endl;

    s+ss;
    s+=sss;
    sssss=s+ssss;
    cout<<sssss<<endl;
    cout<<sssss.str_size()<<endl;

    return 0;
  }
