#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

/*
int add(int num1, int num2){return num1+num2;}
int sum(int num1, int num2){return num1-num2;}
//==int compute(int (*operation)(int, int), int num1, int num2){return operation(num1,num2);}
typedef int (*fptrOperation)(int ,int);
int compute(fptrOperation operation, int num1, int num2){return operation(num1,num2);}
*/

typedef int (*fptrOperation)(const char*, const char*);
//const char* s1 <-- prevent any change of value s1(address)
int compare(const char* s1, const char *s2){
  return strcmp(s1,s2);//s1>s2 return 1
}

char* stringToLower(const char* string){
  char *tmp=(char*)malloc(strlen(string)+1);//allocated address into tmp
  char *start=tmp;//addressv(this time allocated address of tmp)
  while(*string!=0){//while *string has character
    *tmp=tolower(*string);
    ++tmp;// one character one byte so ++temp
    ++string;
  }
  return start;//return allocated malloc address
}

int compareIgnoreCase(const char* s1,const char* s2){
  char* t1=stringToLower(s1);//allocated address by malloc in stringToLower
  char* t2=stringToLower(s2);
  int result=strcmp(t1,t2);
  free(t1);
  free(t2);
  return result;
}

//*array[] array of addresses -> in this case, addresses contain string address
void sort(char *array[], int size, fptrOperation operation){
  int swap=1;
  while(swap){
    swap=0;
    for(int i=0;i<size-1;++i){
      if(operation(array[i],array[1+i])>0){//Ex "Bob"(0x400), "Ted"(0x403)
        swap=1;
        char *tmp=array[i];//array[i] contain address("Bob")
        array[i]=array[1+i];
        array[1+i]=tmp;
      }
    }
  }
}

void displayNames(char *names[],int size){
  for(int i=0;i<size;++i)cout<<names[i]<<" ";
  cout<<endl;
}

int main(){
/*

//c++ style string -> c style array
cout<<"Please input string > ";
string a_string("Something");
//cin>>a_string;//No space permitted!!
getline (cin,a_string);//space permitted
char c_style[a_string.size()+1];//
strcpy(c_style,a_string.c_str());
cout<<strlen(c_style);

//c -> c++
a_string=c_style;
cout<<a_string<<endl;
*/

/*
char name[]="satoshi";
char last[]="Satoshi";
cout<<compare(name,last)<<endl;// ' '32, A65, a97, z122;
//cout<<compute(add,4,5)<<endl;
*/

char* names[]={"Bob","Ted","alice","Alice","Carol"};
sort(names,5,compare);
displayNames(names,5);
sort(names,5,compareIgnoreCase);
displayNames(names,5);





  return 0;
}
