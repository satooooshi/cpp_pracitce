#include<iostream>
#include<fstream>
#include<vector>
using namespace std;



//row left right
//column up down
bool solveMazeRecursive(int row, int col, vector<vector<int>> &maze) {
  //cout<<"hey";

  //already occupied spaces
  //wall
  if(maze[row][col]==1){
    return false;
  }
  //steps
  if(maze[row][col]==2){
    return false;
  }
  //goal
  if(col==maze[row].size()-1&&row==maze.size()-1){
    maze[row][col]=2;
    return true;
  }

  //new area
  maze[row][col]=2;

  //right
  if(col+1<maze[row].size())
  if(solveMazeRecursive(row,col+1,maze)==true){
    return true;
  }
  //down
  if(row+1<maze.size())
  if(solveMazeRecursive(row+1,col,maze)==true){
    return true;
  }

  //left
  if(col-1>=0)
  if(solveMazeRecursive(row,col-1,maze)==true){
    return true;
  }

  //up
  if(row-1>=0)
  if(solveMazeRecursive(row-1,col,maze)==true){
    return true;
  }
  maze[row][col]=0;
  return false;
}



int main(){

ifstream ifs ("m.txt", std::ifstream::in);
int row=0;
int col=0;
ifs>>row>>col;
vector<vector<int>>data(row);

   char c;
   for(int i=0;i<row;++i){
     for(int j=0;j<col;++j){
       ifs>>c;
       data[i].push_back(c-48);
     }
   }
ifs.close();


for (int i = 0; i < data.size(); i++)
{
    for (int j = 0; j < data[i].size(); j++)
    {
        cout << data[i][j];
    }
    cout<<endl;
}
cout<<endl;


solveMazeRecursive(0,0,data);


for (int i = 0; i < data.size(); i++)
{
    for (int j = 0; j < data[i].size(); j++)
    {
        cout << data[i][j];
    }
    cout<<endl;
}
cout<<endl;

  return 0;
}
