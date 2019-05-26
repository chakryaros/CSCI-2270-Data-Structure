#include <iostream>

using namespace std;

int insertArrayElement(int* A[], int v, int index, int numElement)
{
	for(int i=numElement-1; i>=index; i--)
	{
		*A[i+1]=*A[i];
	}
	*A[index]=v;
	numElement++;
	return 0;
}
int* doubleArray(int A[], int numElement)
{
	int B[numElement*2];
	for(int i=0; i<numElement; i++)
	{
		B[i]=A[i];
	}
	return 0;
}
int main()
{
	int numElement=10;
	int array[]={0,1,2,3,4,5,6,7,8,9};
	cout<<"Before: ";
	for(int i=0; i<numElement; i++)
	{
		cout<<array[i]<<", ";
	}
	cout<<endl;
	int value = 10;
	int index = 7;
	insertArrayElement(&array, value, index, 10);
	cout<<"After: ";
	for(int i=0; i<numElement; i++)
	{
		cout<<array[i]<<", ";
	}
	cout<<endl;
	/*
	doubleArray(array, numElement);
	cout<<"doubleArray: ";
	for(int i=0; i<numElement; i++)
	{
		cout<<array[i]<<", ";
	}
	*/
	return 0;
}
