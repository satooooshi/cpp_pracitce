#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

void encode(char *array,int *t, int size){
  int num[]={8,7,3,4,9,6,2};
  int coded;
  int cnt;
  for(int i=0;i<size;++i){
    cnt=i%7;//i%7 : 0~6 in num array
    coded=array[i]+num[cnt];
    if((coded<' ') || (coded>'z')){
      t[i]=(coded-num[cnt])/num[cnt];//ex. 24/9=2 24%9=6 coded -> 6+9*2 decoded
      coded=array[i]%num[cnt]+32;//asc2 less than 32 cant be outputted!!
      //cout<<"array "<<(char)array[i]<<" code "<<coded<<endl;
    }else{
      t[i]=0;
      cout<<"array "<<(char)array[i]<<" coded "<<coded<<endl;
    }
    array[i]=coded;
  }
}


void decode(char *array,int* t, int size){
  int num[]={8,7,3,4,9,6,2};
  int decoded=0;
  for(int i=0;i<size;++i){
    if(t[i]>0){
      decoded=array[i]-32;
      //cout<<array[i]<<decoded<<endl;
      //cout<<t[i]<<endl;
      decoded+=t[i]*num[i%7];
    }
    else
      decoded=array[i]-(num[i%7]);//i%7 : 0~6 in num array
    array[i]=decoded;
  }

}


void display(char *array,int size){
  //for(int i=0;i<size;++i)cout<<(int)array[i];
  for(int i=0;i<size;++i)cout<<array[i];
  cout<<endl;
}


int main(){
char array='w';
int num=5;
int coded=array%num;
coded=array%2;
cout<<coded<<endl;

//c++ style string -> c style array
cout<<"Please input string > ";
string a_string;
getline (cin,a_string);
char c_style[a_string.size()+1];
strcpy(c_style,a_string.c_str());


int temp[a_string.size()+1];
encode(c_style,temp,a_string.size()+1);
cout<<"Coded string > ";
display(c_style,a_string.size()+1);
decode(c_style, temp, a_string.size()+1);
cout<<"Decoded string > ";
display(c_style,a_string.size()+1);

return 0;
}
