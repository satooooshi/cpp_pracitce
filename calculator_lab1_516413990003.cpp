//coded under OS X environment

#include<iostream>
#include<cmath>
#include<vector>
using namespace std;


const char memory ='M';
const char recover='R';
const string memkey="M";
const string reckey="R";
const char quit='q';
const char print=';';
const char number='8';
const char naming='a';
const char let='L';
const string declkey="let";
const string prompt="> ";
const string result="= ";


double expression();
double term();
double primary();

//for MR function
double mem=0;
int flag=0;
double pre_print_ans=0;
double getRec(){return mem;}
void setMem(double d){mem=d;}
//------------------------------------------------------------------------------

class Invalid{
public:
  string error;
  int e_val;
  char bad_ch;
  void what(){
    cerr<<"Error! "
        <<error<<" "
        <<bad_ch<<endl;
      }
};

class Variable{
public:
  string name;
  double value;
  Variable(string n, double v)
    :name(n),value(v){}
};

class Token {
public:
    char kind;
    double value;
    string name;
    Token(char ch)    // for operator
        :kind(ch){}
    Token(char ch, double val)    //for number
        :kind(ch), value(val){}
    Token(char ch, string n)   //for Variable
        :kind(ch),name(n){}
};

class Token_stream{
public:
  Token_stream():full(false),buffer(0){}//: put ':full(false),buffer(0){}' together
  Token get();
  void putback(Token t);
  void ignore(char c);
private:
  bool full;
  Token buffer;
};

class Symbol_table{
private:
  vector<Variable>var_table;
public:
  double get(string n);
  void set(string n,double v);
  bool isDeclared(string n);
  double declare();
};


Token_stream ts;
Symbol_table syt;
//------------------------------------------------------------------------------


// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full)throw Invalid{"putback() into a full buffer"};
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

       // provides get() and putback()
Token Token_stream::get(){
    if (full) {       // do we already have a Token ready? if yes, remove token from buffer
        full=false;
        return buffer;
    }
    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)
    switch (ch) {
    case print:    // for "print"
    case quit:    // for "quit"
    case '(':
    case ')':
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
    case '!':
    case '=':
        return Token(ch);        //initialize token t so that t.kind='8',t.value=val
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    {
            cin.putback(ch);         // put digit back into the input stream
            double val;
            cin >> val;              // read a floating-point number
            return Token(number,val);
    }
    case recover:
    {
      double val=getRec();
      return Token(number,val);
    }
    case memory:
      flag=1;
      return Token(ch);
    default:                        //default for variables (let xlength=7;)
      if(isalpha(ch)){
          string s;
          s+=ch;//example let "xlength"<=s
          while(cin.get(ch)&&(isalpha(ch)||isdigit(ch)))s+=ch;
          cin.putback(ch);//example cin>> xlength=43; putback ;
          if(s==declkey)return Token{let};//Token{"L"}
          return Token{naming,s};//Token{'a',"xlength"}//means variable
      }
        throw Invalid{"bad token!",0,ch};
    }
}


//make back door --> dont start error handling with char c
void Token_stream::ignore(char c){
  if(full&&c==buffer.kind){    //acceptable token return nothing
    full=false;
    return;
  }
  full=false;
  char ch=0;
  while(cin>>ch)//Ex. c==; -> 2+@:];[@]:4; then ignore @:];[@]:4;(till ; appear)
    if(ch==c)return;
}
//------------------------------------------------------------------------------


double Symbol_table::get(string n){
  for(Variable vari:var_table)if(vari.name==n)return vari.value;
  throw Invalid{"unknown variable"};
}

void Symbol_table::set(string n, double v){
  Variable v1(n,v);
  var_table.push_back(v1);
}

bool Symbol_table::isDeclared(string n){
  for(Variable vari:var_table)if(vari.name==n)return 1;
  return 0;
}

double Symbol_table::declare(){
  Token t=ts.get();
  if(t.kind!=naming)throw Invalid{"name expected in declaration"};
  string var_name=t.name;//processed at stream::get default

  if((t.name==memkey)||(t.name==reckey))throw Invalid{"'M' and 'R' cant be assigned"};

  for(Variable vari:var_table)if(isDeclared(var_name))throw Invalid{"name already declared"};

  Token t2=ts.get();
  if(t2.kind!='=')throw Invalid{"= missing in declaration of "};

  double d=expression();
  set(var_name,d);
  return d;
}
//------------------------------------------------------------------------------


double statement(){
  Token t=ts.get();
  switch(t.kind){
    case let:       //if(s==declkey)return Token{let};
      return syt.declare();
    default:
      ts.putback(t);
      return expression();
  }
}


void calculate(){

  while(cin){
    try{
      cout<<prompt;
      Token t=ts.get();
      while(t.kind==memory){t=ts.get();setMem(pre_print_ans);}
      while(t.kind==print)t=ts.get();////ex while (;;;;;;;;) ts.get() till last;
      if(t.kind==quit)return;
      ts.putback(t);//Ex if 5+4;(now 5) -> (now NONE)
      pre_print_ans=statement();
      cout<<result<<pre_print_ans<<endl;//print result
    }catch(Invalid& e){
      e.what();
      ts.ignore(print);
    }
  }
}


int main(){
  try{
    syt.set("pi",3.1415926535);
    syt.set("e",2.7182818284);
    calculate();
    return 0;
  }catch(Invalid& e){
    e.what();
    return 1;
  }catch(...){
    cerr<<"Exception: unknow error, program terminated"<<endl;
    return 2;
  }
  return 0;
}
//------------------------------------------------------------------------------


double expression(){
  double left=term();
  Token t=ts.get();//get kind and value form Token

  while(true){
    switch (t.kind){
      case '+':
        left+=term();// term() has return value double
        t=ts.get();
        break;//to the outside of which
      case '-':
        left-=term();
        t=ts.get();
        break;
      default:
        ts.putback(t);//if not '+' and '-', put the t back to stream
        return left;
    }
  }
}


double term(){
  double left=primary();
  Token t=ts.get();
  while(true){
    switch(t.kind){
      case '*':
        left*=primary();
        t=ts.get();
        break;
      case '/':
      {
        double d=primary();
        if(d==0)throw Invalid{"diveded by zero"};
        left/=d;
        t=ts.get();
        break;
      }
      case '%':
      {
        double d=primary();
        if(d==0)cout<<"divided by zero"<<endl;
        if(d-(int)d!=0 || left-(int)left!=0)throw Invalid{"divided by zero"};
        left=fmod(left,d);
        t=ts.get();
        break;
      }
      default:
        ts.putback(t);
      return left;
    }
  }
}

double primary(){
  Token t=ts.get();
  switch(t.kind){
    case '(':
      {
        double d=expression();
        t=ts.get();
        if(t.kind!=')')throw Invalid{" ')' expected"};
        return d;
      }
    case number:
    {
      double d=t.value;
      t=ts.get();
      if(t.kind=='!'){
        if(d>1 && d-(int)d==0)for(int i=d-1;i>=1;--i)d*=i;
        else if(d==0 || d==1)d=1;
        else if(d < 0)throw Invalid{"invalid operation"};
        else throw Invalid{"invalid operation"};
      }else
        ts.putback(t);
      return d;
    }
    case '+':
    {//no {} result in re difinition of double d=primary();
        double d=primary();
        return d;
    }
    case '-':
    {
        double d=primary();
        return -d;
    }
  case naming:
      return syt.get(t.name);  // if 4+6*xlength (xlength naming) Variable
  default:
      throw Invalid{"primary expected",1};
  }
}
//------------------------------------------------------------------------------
