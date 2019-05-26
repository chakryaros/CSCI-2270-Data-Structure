#include <iostream>

using namespace std;

int *ArrayDyNamicAllocation(int Array[], int size, int number) {
	
	int *newArray = NULL;
	int *tempArray = new int[size];
	for(int i=0; i<size; i++)
	{
		tempArray[i]= Array[i];
	}

	for(int i=0; i<number; i++)
	{
		newArray = new int[size*2];
		for(int j=0; j<size; j++){
			newArray[j]= tempArray[j];
			newArray[j+size] = 2*tempArray[j];
		}
		delete [] tempArray;
		size = size*2;
		tempArray = new int[size];
		for(int k=0; k<size; k++)
		{
			tempArray[k] = newArray[k];
		}
	}
	for(int i=0; i<size; i++)
		{
			cout<<newArray[i]<<" ";
		}
	delete [] tempArray;
	return tempArray=newArray;
}

void findInstanceValue(int array[], int size, int value)
{
	for(int i=0; i<size; i++)
	{
		if(array[i]==value)
		{
			for(int j=i; j<size; j++)
			{
				array[j]=array[j+1];
			}
			size = size -1;
		}
	}
	cout<<"After remove: ";
	for(int i=0; i<size; i++)
	{
		cout<<array[i]<<" ";
	}
}

void copyArrayExpectvalue(int array[], int size, int value)
{
	int newArray[size];
	for(int i=0; i<size; i++)
	{
		if(array[i]!=value)
		{
			newArray[i]=array[i];
		}
		else {
			newArray[i]= array[i+1];
		}
	}
	cout<<"after copy: ";
	for(int i=0; i<size; i++)
	{
		cout<<newArray[i]<<" ";
	}
}

int main() {
	int arr[2] ={0, 1};
	int arraySize =2;
	int numberOfDouble = 3;
	//ArrayDyNamicAllocation(arr, 2, 3);
	int arr1[10] = {1, 2 ,3 ,5,5, 6 ,7, 8,9,10};
	int size = 10;
	findInstanceValue(arr1, size, 5);
	int arr2[10] = {1, 2 ,3 ,4 ,5, 6 ,7, 8,9,10};
	//cout<<"copy array: ";
	//copyArrayExpectvalue(arr2, 10, 2);


	return 0;

}