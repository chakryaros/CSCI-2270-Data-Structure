//Author: Chakrya Ros
//Instructor:Christopher Godley
//TA: Shudong Hao
//Date: 7/08/2018
//Assignment4

#include "MovieTree.hpp"
#include <iostream>

using namespace std;

MovieTree::MovieTree()
{
	root = NULL;
}
MovieTree::~MovieTree()
{
	DeleteAll(root);
}

/*
* Write function name: printMovieInventory;
*Purpose: to print all movie in tree and lists
*@param NONE
* @return - none
*/
void MovieTree::printMovieInventory()
{
	printMovieInventory(root);
}

/*
* Write function name: countMovieNodes;
*Purpose: to count movie in tree
*@param NONE
* @return - total of movie
*/
int MovieTree::countMovieNodes()
{
	int count =0;
	if(root ==NULL)
	{
		return 0;
	} else {
		countMovieNodes(root, &count);
	}
	return count;
}

/*
* Write function name: deleteMovieNode;
*Purpose: the user's choice to delete the movie in tree
*@param string title to find movie to delete
* @return - none
*/
void MovieTree::deleteMovieNode(std::string title)
{
	MovieNodeBST* temp = root;
	MovieNodeBST* temp_parent = NULL;
	int flag = -1;
	while(temp!= NULL)
	{
		if(title[0] == temp->letter) //found the node
		{

			MovieNodeLL* newtemp;
			MovieNodeLL* prev;
			newtemp = temp->head;
			while(newtemp != NULL)
			{
				prev = newtemp;
				if(newtemp->title == title)
				{
					break;
				}
				newtemp = newtemp->next;
			}

			if (newtemp == NULL){
				cout << "Movie not found" << endl;
				return;
			}
			else {
				if (newtemp == temp->head)
				{
					temp->head = newtemp->next;
					delete newtemp;
				}
				else {
					prev->next = newtemp->next;
					delete newtemp;
				}
			}
		}
		else
		{
			//temp_parent = temp;
			if(title[0] < temp->letter)
			{
				temp = temp->leftChild;
				flag =0;
			}
			else if(title[0] > temp->letter)
			{
				temp = temp->rightChild;
				flag =1;
			}
		}
	}
	//the title is not in the tree
	if (temp == NULL) {
		cout << "Moive not found" << endl;
		return;
	}

	if(flag==0) 
	{
		MovieNodeLL* templeft = temp->head;
		if(templeft->title == title)
		{
			MovieNodeLL* newtemp = templeft;
			templeft = newtemp->next;
			newtemp->next = NULL;
		}
		else 
		{
			MovieNodeLL* newtemp = templeft;
			while(newtemp->next->title != title)
			{
				newtemp = newtemp->next;
			}
			MovieNodeLL* deleting = newtemp->next;
			newtemp->next = newtemp->next->next;
			deleting->next = NULL;
		}
	}
	else 
	{
		MovieNodeLL* tempright = temp->head;
		if(tempright->title == title)
		{
			MovieNodeLL* newtemp = tempright;
			tempright = newtemp->next;
			newtemp->next = NULL;
		}
		else 
		{
			MovieNodeLL* newtemp = tempright;
			while(newtemp->next->title != title)
			{
				newtemp = newtemp->next;
			}
			MovieNodeLL* deleting = newtemp->next;
			newtemp->next = newtemp->next->next;
			deleting->next = NULL;
		}

	}
}

/*
* Write function name: buildNetwork;
*Purpose: add city into linked list
*@param NONE
* @return - none
*/
void MovieTree::addMovieNode(int ranking, std::string title, int releaseYear, int quantity)
{
	MovieNodeBST *nodeBST = root;
	MovieNodeBST* nodeBST_parent = NULL;
	char first_letter = title[0];

	// 1. Find the Tree node
	while ((nodeBST != NULL) && (nodeBST->letter != first_letter)) {
		nodeBST_parent = nodeBST;
		if (first_letter < nodeBST->letter)
		{
			nodeBST = nodeBST->leftChild;
		}
		else {
			nodeBST = nodeBST->rightChild;
		}
	}

	// 2. Check if the tree node exists
	// 2.1 Didn't find the tree node
	if (nodeBST == NULL) {
		MovieNodeBST* new_treenode = new MovieNodeBST(first_letter);
		new_treenode->head = new MovieNodeLL(ranking, title, releaseYear, quantity);
		if (nodeBST == root) {
			root = new_treenode;
		}
		else {
			new_treenode->parent = nodeBST_parent;
			if (new_treenode->letter < nodeBST_parent->letter) {
				nodeBST_parent->leftChild = new_treenode;
			}
			else {
				nodeBST_parent->rightChild = new_treenode;
			}
		}
	}

	// 2.2 Found the tree node
	else {
		MovieNodeLL *movie = new MovieNodeLL(ranking, title, releaseYear, quantity);
		MovieNodeLL* tmp = nodeBST->head;
		while (tmp->next != NULL) {
			tmp = tmp->next;
		}
		tmp->next = movie;
	}
}

/*
* Write function name: findMovie;
*Purpose: to find the movie in tree
*@param string title to search in tree
* @return - none
*/
void MovieTree::findMovie(std::string title)
{
	MovieNodeBST *findMovie;
	findMovie = searchBST(root, title);
	if(findMovie == NULL)
	{
		cout<<"Movie not found.\n";
		return;
	}
	MovieNodeLL *findtemp;
	findtemp = searchLL(findMovie->head, title); 
	if(findtemp != NULL)
	{
		cout<<"Moive Info:" <<endl;
		cout<<"===========" <<endl;
		cout<<"Ranking:" <<findtemp->ranking<<endl;
		cout<<"Title:" <<findtemp->title<<endl;
		cout<<"Year:" <<findtemp->year<<endl;
		cout<<"Quantity:" <<findtemp->quantity<<endl;
	}
	else {
		cout << "Movie not found" << endl;
	}
}

/* Write function name: rentMovie;
*Purpose: user to choose the movie in tree for rent
*@param string title to search in tree
* @return - none
*/
void MovieTree::rentMovie(std::string title)
{
	MovieNodeBST* findMovie;
	findMovie = searchBST(root, title);
	if(findMovie == NULL)
	{
		cout<<"Movie not found."<<endl;
	}
	MovieNodeLL *findtemp;
	findtemp = searchLL(findMovie->head, title);
	if(findtemp != NULL)
	{
		cout<<"Movie has been rented."<<endl;
		cout<<"Movie Info:"<<endl;
		cout<<"==========="<<endl;
		cout<<"Ranking:"<<findtemp->ranking<<endl;
		cout<<"Title:"<<findtemp->title<<endl;
		cout<<"Year:"<<findtemp->year<<endl;
		cout<<"Quantity:"<<findtemp->quantity<<endl;
		findtemp->quantity = (findtemp->quantity) - 1;
	}
	else {
		cout << "Movie not found" << endl;
	}
	if (findMovie->head->quantity < 1)
	{
		deleteMovieNode(findtemp->title);
	}
}

//private Function


/*
* Write function name: DeleteAll;
*Purpose: to delete all the movie in tree
*@param MovieNodeBST pointer
* @return - none
*/
void MovieTree::DeleteAll(MovieNodeBST * node) //use this for the post-order traversal deletion of the tree
{
	if(node == NULL)
	{
		return;
	}
	//go left
	if(node->leftChild !=NULL)
	{
		DeleteAll(node->leftChild);
	}
	MovieNodeLL* temp = node->head;
	MovieNodeLL* temp_next = temp->next;
	while(temp != NULL)
	{
		temp_next = temp->next;
		cout<<"Deleting: "<<temp->title<<endl;
		delete temp;
		temp = temp_next;
	}
	//go right
	if(node->rightChild != NULL)
	{
		DeleteAll(node->rightChild);
	}

	//Delete current node
	
	delete node;
}

/*
* Write function name: printMovieInventory;
*Purpose: to print all movie in tree
*@param MovieNodeBST pointer
* @return - none
*/
void MovieTree::printMovieInventory(MovieNodeBST * node)
{
	if( node == NULL)
	{
		return;
	}
	if(node->leftChild !=NULL)
	{
		printMovieInventory(node->leftChild);
	}
	MovieNodeLL* tmp = node->head;
	while (tmp != NULL) {
		cout<<"Movie: "<<tmp->title <<" "<<tmp->quantity<<endl;
		tmp = tmp->next;
	}
	if(node->rightChild !=NULL)
	{
		printMovieInventory(node->rightChild);
	}
	
	
}

/*
* Write function name: countMovieNode;
*Purpose: to count the movie in tree
*@param MovieNodeBST pointer and int c
* @return - none
*/
void MovieTree::countMovieNodes(MovieNodeBST *node, int *c){
	
	if(node->leftChild)
	{
		countMovieNodes(node->leftChild, c);
	}
	MovieNodeLL* tmp = node->head;
	while (tmp != NULL) {
		tmp = tmp->next;
		(*c)++;
	}
	if(node->rightChild)
	{
		countMovieNodes(node->rightChild, c);
	}
	
}

/*
* Write function name: searchBST;
*Purpose: to search the char in the tree
*@param MovieNodeBST pointer and string title
* @return - pointer that match key
*/
MovieNodeBST* MovieTree::searchBST(MovieNodeBST *node, std::string title) //use this recursive function to find a pointer to a node in the BST, given a MOVIE TITLE
{
	MovieNodeBST *findMovie;
	findMovie = node;

	while(findMovie !=NULL)
	{
		if(findMovie->letter == title[0])
		{
			return findMovie;
		}
		else if(title[0] < findMovie->letter)
		{
			if(findMovie->leftChild == NULL)
			{
				findMovie = NULL;
			} else {
				findMovie = findMovie->leftChild;
			}
		} 
		else if(title[0] > findMovie->letter)
		{
			if(findMovie->rightChild == NULL)
			{
				findMovie = NULL;
			} else {
				findMovie = findMovie->rightChild;
			}
		}
	}
	return findMovie;
}

/*
* Write function name: searchLL;
*Purpose: to search the title in linked list
*@param MovieNodeLL pointer and string title
* @return - pointer that match title
*/
MovieNodeLL* MovieTree::searchLL(MovieNodeLL* head, std::string title) //use this to return a pointer to a node in a linked list, given a MOVIE TITLE and the head of the linked list
{
	MovieNodeLL *temp = head;
	MovieNodeLL *returnNode = NULL;
	bool found = false;

	while((!found) && temp !=NULL)
	{
		if(temp->title == title)
		{
			found = true;
			returnNode = temp;
		}
		else {
			temp = temp->next;
		}
	}
	return returnNode;
}

/*
* Write function name: treMinimun;
*Purpose: to find the smallest value in tree
*@param MovieNodeBST pointer
* @return - point that found
*/
MovieNodeBST* MovieTree::treeMinimum(MovieNodeBST *node) //use this to find the left most leaf node of the BST, you'll need this in the delete function
{
	while(node->leftChild != NULL)
	{
		node = node->leftChild;
	}
	return node;
}




















