#include <iostream>

using namespace std;

int main() {
	int a = 13;
	int b = 14;
	int *bp = &b;
	*bp += 1;
	cout << b << endl;
	cout << bp << "----" << *bp << endl;
	cout << "bp ++" << *bp+1 << endl;
	cout << "a " << a << endl;
}

