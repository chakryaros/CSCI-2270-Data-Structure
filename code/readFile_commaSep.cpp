#include <iostream>
#include <sstream>
#include<fstream>
#include<string>

using namespace std;

int main()
{
	ifstream myFileStream("sampleFileTwo.txt");
	if(!myFileStream.is_open())
	{
		cout <<"File failed to open"<<endl;
		return 0;
	}

	string firstName, lastName, tempString, DOB;
	int age;
	string myString;
	string line;
	while(getline(myFileStream, line))
	{
		stringstream ss(line);
		getline(ss, firstName, ',');
		getline(ss, lastName, ',');
		getline(ss, tempString, ',');
		getline(ss, myString, ',');
		age = stoi(myString);
		getline(ss, tempString, ',');
		getline(ss, DOB, ',');
		DOB = DOB.substr(0,2)+DOB.substr(3,2)+DOB.substr(6,2);
		cout<<"age: "<<age<<endl;
		cout<<"DOB: "<<DOB<<endl;
	}

	myFileStream.close();
}