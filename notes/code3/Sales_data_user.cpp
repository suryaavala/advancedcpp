#include <iostream>

#include "Sales_data.h"

int main() {
  Sales_data curBook("Harry Potter");  
  if (read(std::cin, curBook))  { 
    Sales_data newBook("");    
    while(read(std::cin, newBook)) {   
      if (curBook.getBookName() == newBook.getBookName())  {
        curBook.combine(newBook); 
      } else {
        print(std::cout, curBook) << std::endl; 
        curBook = newBook;    
      }
   }
   print(std::cout, curBook) << std::endl; 
  } else {    
    std::cerr << "No data?!" << std::endl;  
  }
}
