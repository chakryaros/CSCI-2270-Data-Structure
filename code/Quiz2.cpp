#include <iostream>

using namespace std;

void calculateCost(int count, float& subTotal, float taxCost)
{
	if(count<10)
	{
		subTotal = count * 0.50;
	}
	else
	{
		subTotal = count*0.20;
	}
	taxCost= 0.1*subTotal;
}

int main()
{
	float tax = 0.0;
	float subtotal =0.0;
	calculateCost(15, subtotal, tax);
	cout <<"the cost for 15 items is "<< subtotal<<", and the tax for "<<subtotal<<" is "<<tax<<endl;
}