#include <iostream>
#include<fstream>

using namespace std;

struct studentInfo{
	string fName, lname, DOB;
	int studAge;
};
void addStudent(studentInfo *&StudArray, string firstN, string lastN, int sAge, string dateB, int sCount);
void printFunc(studentInfo *&studInfoArray, int *arraySize);
void doubleArray(studentInfo *& CUBoulder, int *arraySize);
void readInFileFunc(int *arraySize, studentInfo *& CUBoulder);
//void deleteStudent(studentInfo *studInofArray[]);

int main()
{
	int arraySize = 4;
	//declare new dynamic array of type studentInfo
	studentInfo *CUBoulder = new studentInfo[arraySize];
	cout<<"main: "<<&CUBoulder<<endl;
	readInFileFunc(&arraySize, CUBoulder);

	printFunc(CUBoulder, &arraySize);
	delete[] CUBoulder;
	return 0;
}

void addStudent(studentInfo *& StudArray, string firstN, string lastN, int sAge, string dateB, int sCount)
{
	StudArray[sCount].fName = firstN;
	StudArray[sCount].lname = lastN;
	StudArray[sCount].studAge = sAge;
	StudArray[sCount].DOB = dateB;
}
void doubleArray(studentInfo *& CUBoulder, int *arraySize){
	//*arraySize mean pointer to the same location as original array size
	*arraySize = *arraySize*2;
	cout<<" doubleArray: "<<&CUBoulder<<endl;
	//declare new array of type studentInfo and dynamic
	studentInfo *temArray = new studentInfo[*arraySize];
	for(int i=0; i< *arraySize/2; i++)
	{
		temArray[i]= CUBoulder[i];
	}
	delete[] CUBoulder;
	CUBoulder = temArray;
}
/*
studentInfo *doubleArray(studentInfo *CUBoulder, int *arraySize){
	*arraySize = *arraySize*2;
	//declare new array of type studentInfo and dynamic
	studentInfo *temArray = new studentInfo[*arraySize];
	for(int i=0; i< *arraySize/2; i++)
	{
		temArray[i]= CUBoulder[i];
	}
	delete[] CUBoulder;
	return temArray;
}
*/
void printFunc(studentInfo *& studInfoArray, int *arraySize){
	for(int i=0; i< *arraySize; i++){
		if(studInfoArray[i].studAge>5)
			cout<<studInfoArray[i].fName<<" "<<studInfoArray[i].lname<<endl;
	}
}
void readInFileFunc(int *arraySize, studentInfo *& CUBoulder){
	//studentInfo pointer to CUBoulder as reference to the same
	//location of CUBoulder
	ifstream sampleFile("SampleFile.txt");
	string firstName, lastName, tempString, DOB;
	int age, stuCount;
	cout<<"readInFileFunc: "<<&CUBoulder<<endl;
	if(sampleFile.is_open())
	{
		while(sampleFile>>firstName>>lastName>>tempString>>age>>tempString>>DOB){
			if(stuCount== *arraySize){
				doubleArray(CUBoulder, arraySize);
			}
			addStudent(CUBoulder, firstName, lastName, age, DOB, stuCount);
			stuCount++;
			//cout<<" number of element in file: "<< stuCount<<endl;
		}
	}else{
		cout<<"File failed to open"<<endl;
		return;
	}
	sampleFile.close();
}
/*
void deleteStudent(studentInfo *studInofArray[]){
	for(int i=0; i<4; i++){
		delete studInofArray[i];
	}
}
*/