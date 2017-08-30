#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){


  int n=0;
  char *article[5]={"the","a","one","some","any"};
  char *noun[5]={"boy","girl","dog","town","car"};
  char *verb[5]={"drove","jumped","ran","walked","skipped"};
  char *prepotision[5]={"to","from","over","under","on"};
  char sentence[50];

  //*sequence[0] can finally output string <-> **sequence[0] character
  char **sequence[6]={article,noun,verb,prepotision,article,noun};
  //for(int i=0;i<6;++i)cout<<sequence[i]<<endl;

  for(int i=0;i<6;++i){
    srand((int)time(0)+i*time(0));// void strand(//enter seed)
    n=rand()%5;//from 0 to 4
    strcat(sentence,sequence[i][n]);
    if(i==5)break;
    strcat(sentence, " ");
  }
  strcat(sentence, ".");
  sentence[0]=sentence[0]-' ';//caps

  for(int i=0;i<30;++i)cout<<sentence[i];
  cout<<endl;



  return 0;
}
