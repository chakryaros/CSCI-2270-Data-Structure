#include<iostream>
#include<fstream>
#include<string>

using namespace std;

struct car 
{
	string color;
	string name;
	int year;
};

int main(int argc, char* argv[])
{
	//cout<<"Hello" << endl;
	// for(int i=0; i<argc; i++)
	// {
	// 	cout<< argv[i]<<endl;
	// }
	// struct car carone;
	// struct car cartwo;

	// carone.color = "red";
	// carone.name = "Toyota";
	// carone.year = 2018;
	// cout <<carone.color << endl;

	// int a[10];
	// struct car car1[30];
	// //struct car car1[stoi(argv[1])];

	// car1[4].color = "blue";
	// cout << car1[4].color<<endl;
	fstream fp(argv[1]);  //the 1 is the first file we want to open
	string line;
	getline(fp, line);
	while(getline(fp, line))
	{
		cout << line<< endl;
	}

	// while(1)
	// {
	// 	int a = getline(fp, line);
	// 	cout << a << endl;
	// 	cout << line << endl;
	// 	if(a < 1) break;

	// }

	fp.close();

	return 0;
}