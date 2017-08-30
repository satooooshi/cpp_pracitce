//difinition 定義
#include"book.h"

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
