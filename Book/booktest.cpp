#include"book.h"

//checking ISBN is acceptable form or not.
void checkForm(const string &s){
  if(s[4]!='-' || s[9]!='-' || s[14]!='-')throw Invalid{};
  for(int i=0;i<14;++i){
    if(i==4||i==9)continue;
    if(((int)s[i]<48)||(57<(int)s[i]))throw Invalid{};
  }
}


int main(){

//test Genre class.
Genre g=Genre(1);
Genre gg=Genre::fiction;

//make two objects of type Book.
Book b("1234-1234-1234-a","C++ programming","Bjarne Stroustrup",2,Genre::nonfiction);
Book bb("4321-4321-4321-b","English Grammer","John Smith",3,Genre(3));

//print Book objects.
cout<<b<<endl;
cout<<bb<<endl;

//ask wheher they(Book b and Book bb) are identical or not.
cout<<(bb==b)<<endl;
cout<<(b!=bb)<<endl;

cout<<endl;

// test borrow and return books.
borrowBook("aikawa satoshi",b);
borrowBook("Mike",b);
returnBook(b);
borrowBook("Mike",b);
whoBorrow(b);

vector<Book>book_shelf;
book_shelf.push_back(bb);
book_shelf.push_back(b);

cout<<endl;

//request a book with ISBN
string s;
cout<<"Input ISBN( NNNN-NNNN-NNNN-N/A ) to search > ";
cin>>s;

//check ISBN is acceptable form or not.
try{ checkForm(s); }catch(Invalid){ cout<<"Invalid ISBN"<<endl; }

Book c(s);
//print requested book if found
for( Book x : book_shelf )if(x==c){ cout<<x; whoBorrow(x); }

return 0;
}
