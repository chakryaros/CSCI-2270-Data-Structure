#include <iostream>

using namespace std;

int passByReference(int *x){
	cout<<"Func:\n\tbefore: "<< *x <<endl;
	*x = *x+1;
	cout<<"Func:\n\tafter: "<< *x <<endl;
	return 0;
}
int main()
{
	int x=10;
	cout<<"Main:\n\tbefore: "<< x <<endl;
	passByReference(&x);
	cout<<"Main:\n\tafter: "<< x <<endl;
	return 0;

}