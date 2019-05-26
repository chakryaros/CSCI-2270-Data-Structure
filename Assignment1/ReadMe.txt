Author: Chakrya Ros
Instructor:Christopher Godley
TA: Shudong Hao
Date: 6/14/2018
Assignment1


This program to write about the struct of garage sale that have three varieable, string of item, bool of sale (for sale is true, wanted is false), integer of price. Firstly, open the file and read them line by line and store them into array of struct.
	- if the items in the array match the new items for sale/wanted,
		-compare the price if the price is match
			- remove items from array
			- print out the item and price
	- if the items in the array not match the new items for sale/wanted,
		-add it into array
		-print out the item, sale and price

How to Run this program in teminal:
g++ Assignment1.cpp -o Assignment1
./Assignment1 garagaSale.txt

