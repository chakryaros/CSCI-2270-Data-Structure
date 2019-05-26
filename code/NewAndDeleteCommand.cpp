#include <iostream>
#include<fstream>

using namespace std;

struct studentInfo{
	string fName, lname, DOB;
	int studAge;
};
void addStudent(studentInfo *StudArray[], string firstN, string lastN, int sAge, string dateB, int sCount);
void printFunc(studentInfo *studInofArray[]);
void deleteStudent(studentInfo *studInofArray[]);

int main()
{
	ifstream sampleFile("sampleFile.txt");
	string firstname, lastName, tempString, DOB;
	int age, stuCount;
	studentInfo *CUBoulder[4];
	cout<<CUBoulder<<endl;
	if(sampleFile.is_open()){
		while(sampleFile>>firstname>>lastName>>tempString>>age>>tempString>>DOB){
			addStudent(CUBoulder, firstname, lastName, age, DOB, stuCount);
			stuCount++;
		}
	}
	else
	{
		cout<<"File failed to open."<<endl;
		return 0;
	}
	printFunc(CUBoulder);
	deleteStudent(CUBoulder);
	sampleFile.close();
	return 0;
}

void addStudent(studentInfo *StudArray[], string firstN, string lastN, int sAge, string dateB, int sCount)
{
	StudArray[sCount] = new studentInfo;
	StudArray[sCount]->fName = firstN;
	StudArray[sCount]->lname = lastN;
	StudArray[sCount]->studAge = sAge;
	StudArray[sCount]->DOB = dateB;
};
void printFunc(studentInfo *studInofArray[]){
	for(int i=0; i<4; i++){
		cout<<studInofArray[i]->fName<<" "<<studInofArray[i]->lname<<endl;
	}
}
void deleteStudent(studentInfo *studInofArray[]){
	for(int i=0; i<4; i++){
		delete studInofArray[i];
	}
}