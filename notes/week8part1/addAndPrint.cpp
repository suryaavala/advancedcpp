#include <iostream>

template <typename T1, typename T2>
void addAndPrint(T1& t1, T2& t2) {
    std::cout << "in func: " << ++t1 << " " << ++t2 << std::endl;	
}

int main() {
    int a = 0, b = 100;
    std::cout << "in main: " << a << " " << b << " " << std::endl;
    addAndPrint(a,b);
    std::cout << "in main: " << a << " " << b << " " << std::endl;
    addAndPrint(1,b);
    addAndPrint(2,200);
}
