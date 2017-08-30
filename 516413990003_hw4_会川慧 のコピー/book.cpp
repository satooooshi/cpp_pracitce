//difinition 定義
#include"book.h"
/*
#include<iostream>
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
*/
Book borrowBook(string person, Book &book){
  if(book.borrow_person!="Nobody"){cout<<"Can not borrow ";whoBorrow(book);return book;}
  book.borrow_person=person;
  return book;
}
Book returnBook(Book &book){
  book.borrow_person="Nobody";
  return book;
}

Book whoBorrow(Book &book){
  cout<<book.title<<", Borrowed by "<<book.borrow_person<<endl;
  return book.borrow_person;
}

ostream &operator<<(ostream &output, Book &book){
  output<<"title:"<<book.title<<endl<<"author:"<<book.author<<endl<<"ISBN:"<<book.isbn<<endl; return output;
  //output<<book.borrow_person<<endl; return output;
}
bool operator==(Book &book1,Book &book2){
  return book1.isbn==book2.isbn;
}
bool operator!=(Book &book1, Book &book2){
  return book1.isbn!=book2.isbn;
}
