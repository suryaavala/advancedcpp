#include "Sales_data.h"

Sales_data::Sales_data(std::istream &is) {
  read(is, *this); 
}

std::string Sales_data::getBookName() const { 
  ++no_of_times_called; 
  return bookName; 
}

double Sales_data::avg_price() const {
  if (units_sold)
  	return revenue/units_sold;
  else
  	return 0;
}

Sales_data& Sales_data::combine(const Sales_data &rhs) {
  units_sold += rhs.units_sold; 
  revenue += rhs.revenue;      
  return *this;
}

std::istream& read(std::istream &is, Sales_data &item) {
  double price = 0; // unit price
  is >> item.bookName >> item.units_sold >> price;
  item.revenue = price * item.units_sold;
  return is; 
}

std::ostream& print(std::ostream &os, const Sales_data &item) {
  os << item.bookName << " " << item.units_sold << " "
     << item.revenue << " " << item.avg_price();
  return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
  Sales_data sum = lhs;  
  sum.combine(rhs);     
  return sum; // must not return it by ref/ptr
}             // look at moving semantics

// init the static member
int Sales_data::counter = 0;
