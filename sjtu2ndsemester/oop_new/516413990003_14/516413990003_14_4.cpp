#include<iostream>
#include<vector>
using namespace std;


template<typename T>
class Set{
  vector<T>elem;
public:
  Set(){elem.clear();};
  Set(vector<T> v){
    for(int i=0;i<v.size();++i)elem.push_back(v[i]);
  }
  friend Set<T> operator+(const Set<T> &sa, const Set<T> &sb){
    Set<T> s;
    for(int i=0;i<sa.elem.size();++i)s.elem.push_back(sa.elem[i]);
    int flag=0;
    for(int i=0;i<sb.elem.size();i++){
      for(int j=0;j<sa.elem.size();j++){
        if(sb.elem[i]==sa.elem[j]){
          flag=1;
          break;
        }
      }
      if(flag==0)s.elem.push_back(sb.elem[i]);
      else flag=0;
    }
  return s;
  }
  friend Set<T> operator-(const Set<T> &sa, const Set<T> &sb){
    Set<T> s;
    int flag=0;
    for(int i=0;i<sa.elem.size();i++){
      for(int j=0;j<sb.elem.size();j++){
        if(sa.elem[i]==sb.elem[j]){
          flag=1;
          break;
        }
      }
      if(flag==0)s.elem.push_back(sa.elem[i]);
      else flag=0;
    }
    return s;
  }
  friend Set<T> operator*(const Set<T> &sa, const Set<T> &sb){
    Set<T> s;
    for(int i=0;i<sa.elem.size();i++){
      for(int j=0;j<sb.elem.size();j++){
        if(sa.elem[i]==sb.elem[j]){
          s.elem.push_back(sa.elem[i]);
          break;
        }
      }
    }
    return s;
  }
  friend ostream &operator<<(ostream &out, const Set<T> &s){
    cout<<"{ ";
    for(int i=0;i<s.elem.size();++i){
      if(s.elem.size()-1==i)out<<s.elem[i];
      else out<<s.elem[i]<<", ";
    }
    cout<<" }";
    return out;
  }
};


int main(){
  vector<int>a={1,2,3,4,5,6,7};
  vector<int>b={5,6,7,8,9,10};
  Set<int> s(a);
  Set<int> ss(b);
  Set<int> sss;
  cout<<s<<endl;
  cout<<ss<<endl<<endl;
  sss=s+ss;
  cout<<sss<<endl;
  sss=s-ss;
  cout<<sss<<endl;
  sss=s*ss;
  cout<<sss<<endl;
  cout<<"---------------------------------------------------------"<<endl;
  vector<string>c={"apple","melon","orange","pineapple","banana"};
  vector<string>d={"pineapple","grape","coconut","strawberry"};
  Set<string> e(c);
  Set<string> ee(d);
  Set<string> eee;
  cout<<e<<endl;
  cout<<ee<<endl<<endl;
  eee=e+ee;
  cout<<eee<<endl;
  eee=e-ee;
  cout<<eee<<endl;
  eee=e*ee;
  cout<<eee<<endl;



  return 0;
}
