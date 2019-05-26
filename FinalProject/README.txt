Author: Chakrya Ros
Instructor:Christopher Godley
TA: Shudong Hao
Date: 7/27/2018
Project


This program to build a graph by read from the file that contain the name of 10 cities and the distacne between them stored as an adjacency martrix. And implement functionality to determine if two cities are adjacent, find the shortest weighted paths using Dijkstra and find the shortest path by runing breadth-first search. 

There are two part of the project.
PartI :
	1. Print vertices to allow user to display the vertices and adjacent vertice

	2. Vertex adjacent take two cities as user inputs and displays True is the vertice are adjacent, and False if they are not adjacent.

	3. Quit to allow user to quit from program

PartII :
	1. Print vertices to allow user to display the vertices and adjacent vertice

	2. Find Districts to determine the cennected cities in the graph and assign those cities the same distict ID by run a depth-first search

	3. Find shortes path to run the a breadth-first search that return the number of edges to traverse along the shortest path, and the name of the vertices along the path.

	4. Find shortest weighted path to run Dijkstra's to find the shortest distace between the two cities and print both distance and the names of the vertiecs along the path.

	5. Quit to allow user to quit from program




How to Run this program part I in terminal:
g++ -std=c++11 GraphPartI.cpp MainPartI.cpp -o partI
./partI zombieCities.txt


How to Run this program part II in terminal:
g++ -std=c++11 GraphPartII.cpp MainPartII.cpp -o partII
./partII zombieCities.txt
