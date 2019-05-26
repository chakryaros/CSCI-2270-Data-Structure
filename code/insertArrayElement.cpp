#include <iostream>

using namespace std;

void insertArrayElement(int array[], int value, int index, int numElement, int size)
{
	//for(int x=index; x<numElement; x++)
	for(int x=numElement-1; x>=index; x--)
	{
		array[x+1]=array[x];
		cout<<"array[x]: "<<array[x+1]<<endl;
	}
	array[index] = value;
	cout<<"array at index: "<<array[index]<<endl;
	numElement = numElement + 1;
	cout<<"numElement: "<<numElement<<endl;
}

int main()
{
	int a[10] = {10, 3 ,2 ,13, 14, 5, 6};
	insertArrayElement(a, 5, 4, 7, 10);
	for(int i=0; i<10; i++)
	{
		cout<<a[i]<<"\t";
	}\t
}