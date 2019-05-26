#include <iostream>

using namespace std;

int passByValue(int x){
	cout << "Func:\n\tbefore: " << x << endl;
	x = x +1;
	cout << "Func:\n\tafter: " << x << endl;

	return 0;
}

int passByReference(int* x){
	cout << "Func:\n\tbefore: " << *x << endl;
	*x = *x +1;
	cout << "Func:\n\tafter: " << *x << endl;

	return 0;
}

int main(){
	int x = 10;

	cout << "::passByValue::" << endl;
	cout << "Main:\n\tbefore: " << x << endl;
	passByValue(x);
	cout << "Main:\n\tafter: " << x << endl;

	cout << endl;

	cout << "::passByReference::" << endl;
	cout << "Main:\n\tbefore: " << x << endl;
	passByReference(&x);
	cout << "Main:\n\tafter: " << x << endl;

	return 0;
}