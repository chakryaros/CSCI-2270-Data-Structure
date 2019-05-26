#include <iostream>

using namespace std;




int main()
{
	// const int SIZE = 5;
	// float scores[SIZE];
	// for(int i=0; i<=SIZE; i++)
	// {
	// 	cout <<"Enter a score\n";
	// 	//cin>>scores[i];


	// 	// int a[30] ="Dogs are better than cats";

	// 	//  a = "No, cats are superior";
	// 	//  cout <<a;
	// }
	float findMe=4;
	int num=4;
	float values[4] = {9, 3, 1, 2};
	bool found = false;
	for (int i=0; !found && i<num; i++)
	{	
    	if (i>0)
        	cout << ";";
   		cout << values[i];
   		if (values[i] == findMe)
       		found = true;
	}

	// float findMe=4;
	// int num=4;
	// float values[4]={9, 3, 1, 2};
	// bool found = false;
	// for(int i=0; i<num; i++)
	// {
	// 	if(values[i]==findMe)
	// 	{
	// 		found = true;
	// 		cout<<findMe<<endl;
	// 		break;
	// 	}
	// 	else
	// 	{
	// 		cout<<values[i]<<";";

	// 	}
	// }
	return 0;
}