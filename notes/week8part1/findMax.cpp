#include <iostream>
#include "numlimits.hpp"	// in reality: <limits>

template< typename T > T findMax(const T* data, int numItems) 
 { 
   // Get the minimum value for type T 
   T largest = numeric_limits<T>::min(); 
 
   for (int i=0; i < numItems; ++i) 
     if (data[i] > largest) 
       largest = data[i]; 
 
   return largest; 
 } 
 
int main() {
	int iArray[] = {-1,-3,-2};
	std::cout << findMax(iArray,3) << std::endl;
	unsigned int iUArray[] = {1,3,2};
	std::cout << findMax(iUArray,3) << std::endl;
	float fArray[] = {4.1,4.3,4.2};
	std::cout << findMax(fArray,3) << std::endl;
}
