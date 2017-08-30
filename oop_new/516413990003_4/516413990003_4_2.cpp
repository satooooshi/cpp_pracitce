#include<iostream>
using namespace std;


int m;//row
int n;//line
int y;//line
int x;//row
int i;
int maxi;
int mini;
int saddle_line1;
int saddle_row1;
int saddle_line2;
int saddle_row2;

int main(){



  cout<<"Please input m,n: ";
  cin>>m>>n;
  int arr[m][n];
  cout<<"Please input array:\n";

  for(x=0;x<m;++x){//row
    for(y=0;y<n;++y){//line
        cin>>arr[x][y];
    }
  }

  //for(x=0;x<m;++x){
  //  for(y=0;y<n;++y){
  //    cout<<arr[x][y];
  //  }
  //  cout<<'\n';
  //}


  //int arr[3][4]={{3,2,1,4},{5,1,6,8},{6,7,8,9}};
  //int arr[3][4]={{1,2,1,1},{1,3,1,3},{1,3,1,3}};
  //m=3;
  //n=4;

for(i=0;i<m;++i){

  x=i;
  y=0;
  maxi=arr[x][y];
  saddle_row1=x;
  saddle_line1=y;
    for(y=0;y<n;++y){
      if(maxi<arr[x][y]){
        maxi=arr[x][y];
        saddle_row1=x;
        saddle_line1=y;
      }
    }
    //cout<<"max: "<<maxi<<"\n";
    //cout<<"saddle_row1"<<saddle_row1<<'\n';
    //cout<<"saddle_line1"<<saddle_line1<<'\n';

  x=i;
  y=saddle_line1;//3
  mini=arr[x][y];//0 3
  saddle_row2=x;
  saddle_line2=y;
    for(x=0;x<m;++x){
      if(mini>arr[x][y]){
        mini=arr[x][y];
        saddle_row2=x;
        saddle_line2=y;
      }
    }
    //cout<<"min: "<<mini<<"\n";
    //cout<<"saddle_row2"<<saddle_row2<<'\n';
    //cout<<"saddle_line2"<<saddle_line2<<'\n';

    if(saddle_line1==saddle_line2 && saddle_row1==saddle_row2){
      cout<<"mat["<<saddle_row1<<"]["<<saddle_line1<<"] = "<<arr[saddle_row1][saddle_line1]<<'\n';
      return 0;
    }

}

    cout<<"Not Found\n";

return 0;
}
