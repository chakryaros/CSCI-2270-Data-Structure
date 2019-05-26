#include <iostream>
#include <fstream>
#include <string>
#include<sstream>
using namespace std;

struct wordItem {
	string word;
	int count;
};
/*
* Write function name: getStopWord;
*Purpose: read stop word list from file and store into an array
*@param ignoreWordFile - filename(the file storing ignore words)
*@param ignoreWords - store ignore words from the file (pass by
reference)
* @return - none
* The number of word is fixex to 50
*/
void getStopWords(string ignoreWordFileName, string ignoreWords[])
{
	ifstream ignore_file(ignoreWordFileName);
	if(ignore_file.fail())
	{
		cout <<" Ignore Word File does not exit.\n";
	}
	string line;
	int index =0;
	while(!ignore_file.eof())
	{
		ignore_file>>line;
		ignoreWords[index] = line;
		index++;
	}
	// for(int i=0; i<index; i++)
	// {
	// 	cout<<ignoreWords[i]<<endl;
	// }
	ignore_file.close();
}
/*
* Function name isStopWord
*Purpose: to see if a word is a stop word
*@param word - a word (which you want to check if it is a stop word)
*@param ignoreWords - the array of strings storing ignore/stop words
*return - true (if word is a stop word), or false(otherwise)
*/
int isStopWord(string word, string ignoreWords[])
{
	bool found = false;
	int i=0;
	while(!found && i<50)
	{
		if(word == ignoreWords[i]){
			found = true;
		}
		else
		{
			i++;
		}
	}
	if(found)
		return 1;
	else
		return 0;
}
int searchNonCommonWord(string CurrrenWord, wordItem *& wordArray, int arraySize)
{
	bool found = false;
	int i=0;
	while(!found && i< arraySize)
	{
		if(CurrrenWord==wordArray[i].word)
		{
			found = true;
		}
		else
		{
			i++;
		}
	}
	if(found)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
/*
void doubleArray( wordItem* & wordArray, int arrayCounter, int arrayMax) //helped from http://stackoverflow.com/questions/35108584/array-of-structs-doubling-algorithm-c
{
    wordItem* temp = new wordItem[arrayMax]; //creates new bigger array - helped from http://www.fredosaurus.com/notes-cpp/newdelete/55dynexample.html

    for (int x = 0; x < arrayCounter; x++)
    {
        temp[x] = wordArray[x]; //copies the old array values into the new array
    }

    delete [] wordArray; //frees old array memory
    wordArray = temp; //now trackerArray points to the new array
}
*/
void doubleArray(wordItem *& word_NonCommon, int *arraySize)
{
	*arraySize =*arraySize*2;
	wordItem *tempArray = new wordItem[*arraySize];
	for(int i=0; i< *arraySize/2; i++)
	{
		tempArray[i] = word_NonCommon[i];
	}
	delete[] word_NonCommon;
	word_NonCommon = tempArray;
}
void printTopN(wordItem wordItemList[], int topN)
{
	for(int i=0; i<topN; i++)
	{
		cout<< wordItemList[i].count<<" - "<< wordItemList[i].word<<endl;
	}
}
void arraySort(wordItem *&List, int *arraySize)
{
	wordItem temp;
	for(int i=0; i<*arraySize; i++)
	{
		for(int j=0; j<*arraySize-1; j++)
		{
			if(List[j+1].count>List[j].count)
			{
				temp = List[j];
				List[j]= List[j+1];
				List[j+1]=temp;
			}
		}
	}
}
/*
*Function name: readInFile

*/
void getTotalNumberNonStopWord(int totalWords)
{
	cout <<"Total non-common words: "<< totalWords <<endl;
}
void readInFile(string hungerGameFile, int *arraySize, int s, wordItem *& word_NonCommon, string ignoreWords[])
{
	fstream file_hunger(hungerGameFile);
	string word;
	int resultStopWord=-1;
	int resultNonComm=-1;
	int countWord=0;
	int countAllWord=0;
	int doubleArrayCount=0;
	if(file_hunger.fail())
	{
		cout <<"File can not open."<<endl;
	}
	while(!file_hunger.eof())
	{
		file_hunger>>word;
		// cout<<word<<endl;
		resultStopWord= isStopWord(word, ignoreWords);
		resultNonComm=searchNonCommonWord(word, word_NonCommon, countWord);
		if(resultStopWord ==0 && resultNonComm==0)
		{
			countAllWord = countAllWord +1;
			if( *arraySize> countWord) {
				word_NonCommon[countWord].word = word;
				word_NonCommon[countWord].count = word_NonCommon[countWord].count+1;
			}
			else
			{
				doubleArrayCount++;
				doubleArray(word_NonCommon, arraySize);
				word_NonCommon[countWord].word = word;
				word_NonCommon[countWord].count = word_NonCommon[countWord].count+1;
			}
			countWord++;
		} 
		else if(resultStopWord ==0 && resultNonComm==1)
		{
			countAllWord = countAllWord +1;
			for(int i=0; i<countWord; i++)
			{
				if(word == word_NonCommon[i].word){
					word_NonCommon[i].count = word_NonCommon[i].count+1;
				}
			}
		}
	}
	arraySort(word_NonCommon, arraySize);
	//s = countAllWord;
	printTopN(word_NonCommon, s);
	cout <<"Array doubled: "<< doubleArrayCount<<endl;
	cout <<"Unique non-common words: "<<countWord<<endl;
	getTotalNumberNonStopWord(countAllWord);
	file_hunger.close();
}
int main(int argc, char* argv[]){
	//readInFile(argv[1]);
	int arraySize = 100;
	wordItem *word_NonCommon = new wordItem[arraySize];
	string wordArray[50];
	getStopWords("ignoreWords.txt", wordArray);
	readInFile("HungerGames_edit.txt", &arraySize, 10, word_NonCommon, wordArray);
	// ifstream file_hunger("HungerGames_edit.txt");
	// string word;
	// int resultStopWord=-1;
	// int resultNonComm=-1;
	// int countWord=0;
	// int countAllWord=0;
	// int doubleArrayCount=0;
	// if(file_hunger.fail())
	// {
	// 	cout <<"File can not open."<<endl;
	// }
	// while(!file_hunger.eof())
	// {
	// 	file_hunger>>word;
	// 	// cout<<word<<endl;
	// 	resultStopWord= isStopWord(word, wordArray);
	// 	resultNonComm=searchNonCommonWord(word, word_NonCommon, countWord);
	// 	if(resultStopWord ==0 && resultNonComm==0)
	// 	{
	// 		countAllWord = countAllWord +1;
	// 		if( arraySize> countWord) {
	// 			word_NonCommon[countWord].word = word;
	// 			word_NonCommon[countWord].count = word_NonCommon[countWord].count+1;
	// 		}
	// 		else
	// 		{
	// 			arraySize = arraySize*2;
	// 			doubleArray(word_NonCommon, countWord, arraySize);
	// 			doubleArrayCount++;
	// 			word_NonCommon[countWord].word = word;
	// 			word_NonCommon[countWord].count = word_NonCommon[countWord].count+1;
	// 		}
	// 		countWord++;
	// 	} 
	// 	else if(resultStopWord ==0 && resultNonComm==1)
	// 	{
	// 		countAllWord = countAllWord +1;
	// 		//cout<<countAllWord<<"test"<<endl;
	// 		for(int i=0; i<countWord; i++)
	// 		{
	// 			if(word == word_NonCommon[i].word){
	// 				word_NonCommon[i].count = word_NonCommon[i].count+1;
	// 			}
	// 		}
	// 	}
	// }
	// file_hunger.close();
	// arraySort(word_NonCommon, arraySize);
	// printTopN(word_NonCommon, 10);
	// getTotalNumberNonStopWord(countAllWord);
	// cout <<" double Arrsy size: "<< doubleArrayCount<<endl;
	delete [] word_NonCommon;
	return 0;
}