#include <iostream>
#include <math.h>

using namespace std

int main(){
	int intx = 12;
	double dblA = 5.67866;

	cout << "Hello world!\n" << endl;

	int intA = 5;
	int intB = 6;
	int intResult = intA + intB;
	cout << "Add Result: " << intResult << endl;

	intResult = intA - intB;
	cout << "\n"
	cout << "Sub Result: " << intResult << "\n";

	double dblA = 5.67866;	// 8 bits of memory
	float fltA = 5.678;		//Holds less memory than a double - 4 bits
	cout << "Double: " << dblA << "\n"
	cout << "Float: " << fltA << "\n";

	float dblArea = 3.14 * pow(10,2);
	cout << "Area: " << dblArea;

	char chrFoo[20]; //Array of 20 characters
	char chrWord[] = {'H', 'E', 'L','L','O', '\0'}
		//chrWord is an array of characters
		//stars at H and goes until \0
			// \0 is a null operator - tells H when to stop
	char chrWord2[] = "HELLO";
		//chrWord and charWord2 will produce the same result
	cout << "First: " << chrWord << ", \t
		Second : " << chrWord2 << "\n";

	// String truncation
	chrWord[2] = '\0'; //Puts a null operator in the [2] slot of the chrWord array
	cout << "First: " << chrWord << ",\t
		Second: " << chrWord2 << "\n"
	
	//Input
	char chrQuestion = "What is your name? ";
	char chrAnswer[50]:
	cout << chrQuestion;
	cin >> chrAnswer;
	cout << "Hello, " << chr chrAnswer << "\n";
	
}