#include <iostream>
#include<iterator>
#include<vector>
#include<string>

using namespace std;

int main()
{
	vector<string> a;

	vector<string>::iterator it;

	a.push_back("abd");
	a.push_back("cba");

	for( it = a.begin(); it != a.end(); it++)
	{
		cout<< (*it) << endl; //if we want to get value at it, need to use *
	}


	// for(int i=0; i< a.size() ; i++)
	// {
	// 	cout<< a[i] << endl;
	// }

	cout<< a.size() <<endl;
	cout<< a.capacity() <<endl;

	return 0;
}