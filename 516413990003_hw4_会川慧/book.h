//declarations:宣言
#include<iostream>
#include<vector>
using namespace std;

class Invalid{
private:
  int value;
public:
  Invalid(int x=-1){value=x;};
};


enum class Genre{
  fiction=1,nonfiction,periodical,biography,children
};


class Book{
private:
  string isbn;
  string title;
  string author;
  int edition;
  Genre gen;
  string borrow_person;
public:
  Book(string i="",string t="",string a="",int e=1, Genre g=Genre::fiction,string p="Nobody"){
    isbn=i;title=t;author=a;edition=e;gen=g;borrow_person=p;
  }
  friend Book whoBorrow(Book &book);
  friend Book borrowBook(string person, Book &book);
  friend Book returnBook(Book &book);
  friend ostream &operator<<(ostream &output, Book &book);
  friend bool operator==(Book &book1,Book &book2);
  friend bool operator!=(Book &book1,Book &book2);
};
