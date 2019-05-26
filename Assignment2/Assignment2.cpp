//Author: Chakrya Ros
//Instructor:Christopher Godley
//TA: Shudong Hao
//Date: 6/22/2018
//Assignment2

#include <iostream>
#include <fstream>
#include <string>
#include<sstream>
using namespace std;


//declare the wordItem of struct object
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
	ifstream ignore_file(ignoreWordFileName); //open the ignoreWords.txt file to read
	if(ignore_file.fail())
	{
		cout <<" Ignore Word File does not exit.\n";
	}
	string line;
	int index =0;
	while(!ignore_file.eof()) //read untile the end of the file
	{
		ignore_file>>line;	//read word by word
		ignoreWords[index] = line; //store it into array of ignoreWord
		index++;
	}
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

/*
*Function name searchNonCommonWord
*Purpose: to check if a word is unique word and repeat word
*@param Current - a word (which is repeat word )
@param wordArray - array of type wordItem store word and count
*@param arraySize - the size of array
*return - 1 (if word is repeat), or -1 (otherwise)
*/

int searchNonCommonWord(string CurrentWord, wordItem *& wordArray, int arraySize)
{
	bool found = false;
	int i=0;
	while(!found && i< arraySize)
	{
		if(CurrentWord==wordArray[i].word) 
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
*Function name doubleArray
*Purpose: to double size of array
*@param word_NonCommon of type wordItem to store word and count
*@param arraySize
*return nothing
*/
void doubleArray(wordItem *& word_NonCommon, int *arraySize)
{
	*arraySize =*arraySize*2; //double arraysize
	wordItem *tempArray = new wordItem[*arraySize]; // declare tempArray of wordItem object
	for(int i=0; i< *arraySize/2; i++)
	{
		tempArray[i] = word_NonCommon[i]; //copy the word_NonCommon array into tempArray
	}
	delete[] word_NonCommon; //delete the word_Noncommon
	word_NonCommon = tempArray; //copy tempArray into word_NonCommon that have double size
}

/*
*Function name printTopN
*Purpose: to print the top element in wordItem array
*@param word_NonCommon of type wordItem to store word and count
*@param topN (the number of element that want to output)
*return nothing
*/
void printTopN(wordItem wordItemList[], int topN)
{
	for(int i=0; i<topN; i++)
	{
		cout<< wordItemList[i].count<<" - "<< wordItemList[i].word<<endl;
	}
}

/*
*Function name arraySort
*Purpose: to decrease the element of count word from high to low
*@param list arrat of type wordItem to store word and count
*@param arraySize
*return nothing
*/
void arraySort(wordItem *&List, int *arraySize)
{
	wordItem temp;
	for(int i=0; i<*arraySize; i++)
	{
		for(int j=0; j<*arraySize-1; j++)
		{
			if(List[j+1].count>List[j].count) //to check if the element of count in index j+1 is greater than index j
			{
				temp = List[j]; //swap
				List[j]= List[j+1];
				List[j+1]=temp;
			}
		}
	}
}

/*
*Function name getTotalNumberNonStopWord
*Purpose: to compute the total number of words saved in the words array
(including repeated words)
*@param totalWord
* output the totalWords
*/
void getTotalNumberNonStopWord(int totalWords)
{
	cout <<"Total non-common words: "<< totalWords <<endl;
}

/*
*Function name readInFile
*Purpose: to open file and read and store into words array
*@param string file name
*@param arraySize
*@param top of char (to get top repeat word)
*@param word_NonCommon of type wordItem to store word and count
*@param arrray of ignoreword
*return nothing
*/
void readInFile(string hungerGameFile, int *arraySize, char* top, wordItem *& word_NonCommon, string ignoreWords[])
{
	fstream file_hunger(hungerGameFile); //open the file of hungerGames_edit.txt
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
		file_hunger>>word; //read each word in the file
		if(word.length() !=0) {

			resultStopWord= isStopWord(word, ignoreWords); //call the isStopWord function to check common word
			resultNonComm=searchNonCommonWord(word, word_NonCommon, countWord); //call the searchNoncommoWord to check the repeat unqiue word
			if(resultStopWord ==0 && resultNonComm==0) //if the no commmon word and no repeat the unique word
			{
				countAllWord = countAllWord +1;  //count the unique word in array
				//if the arraySize is less than 100
				if( *arraySize> countWord) { 
					word_NonCommon[countWord].word = word; //add word intot word arrat
					word_NonCommon[countWord].count = word_NonCommon[countWord].count+1; //add count and increment by 1
				}
				else
				{
					doubleArrayCount++;
					doubleArray(word_NonCommon, arraySize); //call doubleArray function to double size 
					word_NonCommon[countWord].word = word;
					word_NonCommon[countWord].count = word_NonCommon[countWord].count+1;
				}
				countWord++;
			} 
			else if(resultStopWord ==0 && resultNonComm==1) //if the no commmon word and repeat the unique word
			{
				countAllWord = countAllWord +1;
				for(int i=0; i<countWord; i++)
				{
					if(word == word_NonCommon[i].word){
						word_NonCommon[i].count = word_NonCommon[i].count+1; //add count of repeat word
					}
				}
			}
		}
	}
	arraySort(word_NonCommon, arraySize); //call arraySort function to sort the word in array
	int TopWord = stoi(top); //convert char top into integer
	printTopN(word_NonCommon, TopWord);
	cout<<"#"<<endl;
	cout <<"Array doubled: "<< doubleArrayCount<<endl;
	cout<<"#"<<endl;
	cout <<"Unique non-common words: "<<countWord<<endl;
	cout<<"#"<<endl;
	getTotalNumberNonStopWord(countAllWord); //call the getTotalNumberNonStopWord to print the total of word in arrray
	file_hunger.close();
}

int main(int argc, char* argv[]){
	int arraySize = 100;
	wordItem *word_NonCommon = new wordItem[arraySize]; //declare the new dynamic array of wordItem object
	string wordArray[50];
	getStopWords(argv[3], wordArray);
	readInFile(argv[2], &arraySize, argv[1], word_NonCommon, wordArray); //call the readInFile;
	delete [] word_NonCommon; //delete the dynamic array from memory
	return 0;
}