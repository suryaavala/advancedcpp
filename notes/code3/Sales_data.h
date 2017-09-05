#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>

class Sales_data {
public:
  // constructors
  Sales_data(const std::string &s): bookName(s) { ++counter; }
  Sales_data(const std::string &s, unsigned n, double p):
             bookName(s), units_sold(n), revenue(p*n) { }
  Sales_data() : Sales_data("", 0, 0) { }
  Sales_data(std::istream &);
  
  // operations on Sales_data objects
  std::string getBookName() const;
  Sales_data& combine(const Sales_data&);
  double avg_price() const;
  
private:
  std::string bookName;
  unsigned units_sold = 0; // in-class initialiser
  double revenue = 0.0;    // in-class initialiser
  
  // counts no. of times getBookName() called on a Sales_data object
  mutable unsigned no_of_times_called = 0; 
  
  // Count how many objs are created by this constructor
  static int counter;
  
  friend std::istream& read(std::istream &is, Sales_data &item);
  friend std::ostream& print(std::ostream&, const Sales_data&);
};

std::istream& read(std::istream &is, Sales_data &item);
std::ostream& print(std::ostream&, const Sales_data&);

Sales_data add(const Sales_data&, const Sales_data&);

#endif
