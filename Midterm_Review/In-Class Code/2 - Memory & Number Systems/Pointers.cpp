#include <iostream>

using namespace std;

int main(){
	int X = 4;
	int *ptrX = &X;

	cout << "X: \t \t" << X << "\n";
	cout << "&X: \t" << &X << "\n";

	cout << "ptrX: \t" << ptrX << "\n";
	cout << "&ptrX: \t" << &ptrX << "\n";
	cout << "*ptrX: \t" << *ptrX << "\n";

	return 0;
}