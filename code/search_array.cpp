#include<iostream>
using namespace std;

// int searchArray(int array[], int size, int target)
// {
// 	bool found = false;
// 	int i=0;
// 	while(!found && i<size)
// 	{
// 		if(array[i]==target)
// 		{
// 			found = true;
// 		}
// 		else
// 		{
// 			i++;
// 		}
// 	}
// 	if(found)
// 	{
// 		return i;
// 	}
// 	else
// 	{
// 		return -1;
// 	}
// }

int searchArray(int array[], int size, int target)
{
	bool found = false;
	int j=0;
	for(int i=0; i<size && !found; i++)
	{
		if(array[i]==target)
		{
			found = true;
			j=i;
		}
	}
	if(found)
	{
		return j;
	}
	else
	{
		return -1;
	}
}

int main()
{
	int a[10] = {1, 2 ,3 ,45, 67, 89, 56, 78, 43,35};
	int result = searchArray(a, 10, 45);
	cout<<"Array found at index: "<<result<<'\n';
}