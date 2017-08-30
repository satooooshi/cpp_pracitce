#include<iostream>
using namespace std;

int subZeller( int y, int m, int d )
{
    if( m < 3 ) {
        y--; m += 12;
    }
    return ( y + y/4 - y/100 + y/400 + ( 13*m + 8 )/5 + d )%7;
}

int main()
{
    int year, mon, day;
    int dayname[] = {0,1,2,3,4,5,6};//0 sun, 6 sat
    int month[]={31,28,31,30,31,30,31,31,30,31,30,31};
    int sun,mond,tue,wen,thu,fri,sat;
    int which_day;
    int year_end;
    int i,j,n;
    sun=0;
    mond=0;
    tue=0;
    wen=0;
    thu=0;
    fri=0;
    sat=0;

        //cout<< "Enter a interval of year from 1900 > ";
        cin>>n;
        year_end=1899+n;//if input 20 then year=1919
        //cout<<"From 1900 to "<<year_end<<'\n';
        //cout<<"--> "<<dayname[subZeller(year,month,day)]<<'\n';

for(year=1900;year<=year_end;++year){

    if(year%4==0 && year%100==0 && year%400==0)//luner_month or not
      month[1]=29;
    else
      month[1]=28;

      for(mon=0;mon<12;++mon){
        for(day=1;day<=month[mon];++day){
          which_day=subZeller(year,mon+1,day);
          //cout<<"which_day"<<year<<":"<<mon+1<<":"<<day<<">"<<which_day<<'\n';
          if(5==which_day && day==13){//indicate black friday
            ++fri;
          }else if(6==which_day && day==13){
            ++sat;
          }else if(0==which_day && day==13){
            ++sun;
          }else if(1==which_day && day==13){
            ++mond;
          }else if(2==which_day && day==13){
            ++tue;
          }else if(3==which_day && day==13){
            ++wen;
          }else if(4==which_day && day==13){
            ++thu;
          }
        }
      }
}
      //cout<<"From monday to sunday > "<<mond<<" "<<tue<<" "<<wen<<" "<<thu<<" "<<fri<<" "<<sat<<" "<<sun<<'\n';
      cout<<mond<<" "<<tue<<" "<<wen<<" "<<thu<<" "<<fri<<" "<<sat<<" "<<sun<<'\n';
    return 0;
}
