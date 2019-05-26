Author: Chakrya Ros
Instructor:Christopher Godley
TA: Shudong Hao
Date: 6/22/2018
Assignment2


This program to write about the struct of wordItem that have two varieable, string of word, and int of count. The purpose is to read the from the file and analize the word, store the unique words found in the dynaminically allocated array. There are eight function for this program to run:
	- void getStopWords : open the file and store stop word into array
	- int isStopWord : to check if a word is a stop word and return.
	- int searchNonCommonWord: to check if a word is uniqure word
	- void doubleArray: to double size of array
	- void printTopN: to print the top word count in dynamic array
	- void arraySort: to sort the word count in array by decressing
	- void getTotalNumberNonStopWord: to print the total unique word in array
	- void readInFile: to read file and store unique word in array

How to Run this program in terminal:
g++ Assignment2.cpp -o Assignment2
./Assignment2 <number of top word count> HungerGames_edit.txt ignoreWords.txt

