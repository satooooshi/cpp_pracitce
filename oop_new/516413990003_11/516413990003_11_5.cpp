#include<iostream>
using namespace std;

class SavingAccount{
private:
  static int account_num;
  static int passed_month;
  int my_num;
  double saving;
  double percentage;
  int starting_date;
public:
  SavingAccount(double s, double p);
  SavingAccount(const SavingAccount&)=delete;
  SavingAccount &operator=(const SavingAccount&)=delete;
  void MonthCount();
  void display();
};

int SavingAccount::account_num=0;
int SavingAccount::passed_month=0;

SavingAccount::SavingAccount(double s, double p)
:saving{s},percentage{p},starting_date{passed_month}
{
  ++account_num;
  cout<<"Account number : No."<<account_num
  <<", month per rate : "<<percentage<<" % "
  <<"saving : $"<<saving
  <<endl;
  my_num=account_num;
}

void SavingAccount::display(){
  double sum=saving;
  for(int i=0;i<passed_month-starting_date;++i)
    sum+=sum*percentage;
  saving=sum;
  cout<<"Total saving month(s) : "<<passed_month-starting_date
      <<", Account number No."<<my_num
      <<", Saving : $"<<saving<<endl;
}

void SavingAccount::MonthCount(){
  ++passed_month;
}
int main(){
  SavingAccount sv1(100,0.1),sv2(200,0.7);
  sv1.display();
  sv2.display();
  sv1.MonthCount();
  sv1.MonthCount();
  sv1.display();
  sv1.MonthCount();
  sv1.MonthCount();
  sv2.display();
return 0;
}
