#include<iostream>
using namespace std;

class Time{
private:
  int hour;
  int min;
  int sec;

public:
  Time(int h=0,int m=0,int s=0){
    hour=h;
    min=m;
    sec=s;
  }
  static int sel;
  friend void operator+=(Time &ta, int a);
  friend void operator-=(Time &ta, int a);
  friend ostream &operator<<(ostream &output, Time &t);
  friend Time operator-(Time &ta, Time &tb);

};
int Time::sel=0;


void operator+=(Time &ta, int a){
  //if(60<a)a%=60;
  ta.sec+=a;
  if(ta.sec>=60){
    ta.min+=1;
    ta.sec-=60;
  }
  if(ta.min>=60){
    ta.hour+=1;
    ta.min-=60;
  }
  if(ta.hour>=24){
    ta.hour-=24;
  }
  return ;
}
/*
Time operator-(Time &ta, Time &tb){
  if(60<tb.hour)tb.hour%=60;
  if(60<tb.min)tb.min%=60;
  if(60<tb.sec)tb.sec%=60;
  ta.hour-=tb.hour;
  ta.min-=tb.min;
  ta.sec-=tb.sec;
  if(ta.sec<0){
    ta.min-=1;
    ta.sec+=60;
  }
  if(ta.min<0){
    ta.hour-=1;
    ta.min+=60;
  }
  if(ta.hour<0){
    ta.hour+=24;
  }
  return ta;
}
*/
Time operator-(Time &ta, Time &tb){
  //if(60<tb.hour)tb.hour%=60;
  //if(60<tb.min)tb.min%=60;
  //if(60<tb.sec)tb.sec%=60;
  ta.hour-=tb.hour;
  ta.min-=tb.min;
  ta.sec-=tb.sec;


  ta.sec=ta.hour*3600+ta.min*60+ta.sec;

  return ta;
}

void operator-=(Time &ta, int a){
  //if(60<a)a%=60;
  ta.sec-=a;
  if(ta.sec<0){
    ta.min-=1;
    ta.sec+=60;
  }
  if(ta.min<0){
    ta.hour-=1;
    ta.min+=60;
  }
  if(ta.hour<0){
    ta.hour+=24;
  }
  return ;
}

ostream &operator<<(ostream &output, Time &t){
  if(Time::sel==3&&t.sec!=1&&t.sec!=-1){output<<t.sec<<" seconds";return output;}
  else if(Time::sel==3&&t.sec==1){output<<t.sec<<" second";return output;}
  else if(Time::sel==3&&t.sec==-1){output<<t.sec<<" second";return output;}
  output<<t.hour<<":"<<t.min<<":"<<t.sec;
  return output;
}

int main(){

  int h;
  int m;
  int s;
  int x=10;
  cin>>Time::sel;
  cin>>h>>m>>s;

  //Time t(12,13,14);
  Time t(h,m,s);
  if(Time::sel==1){
    cin>>x;
    t+=x;
    cout<<t<<endl;
  }else if(Time::sel==2){
    cin>>x;
    t-=x;
    cout<<t<<endl;
  }else if(Time::sel==3){
    int h;
    int m;
    int s;
    int x=10;
    cin>>h>>m>>s;
    //Time tt(12,13,14);
    Time tt(h,m,s);
    t-tt;
    cout<<t<<endl;
  }



  return 0;
}
