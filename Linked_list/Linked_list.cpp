#include <iostream>
// #ifndef LINKLIST_H
// #define LINKLIST_H

using namespace std;

struct node{
	int data;
	node *next;
	
};

node *head;
void traverse()
{
	node *list;
	node *pass;
	//traverse the entire list
	for(list=head; list->next!=NULL; list = list->next)
	{
		//compare and swap
		if(list->data > pass->data)
		{
			//swap
			int temp = list->data;
			list->data = pass->data;
			pass->data = temp;
		}
	}
}
node* search(int value)
{
	//start at the root
	node* currentNode = head;

	//loop through the entire list
	while(currentNode !=NULL)
	{
		//if we have a match
		if(currentNode->data==value)
			return currentNode;
		else //move to the next element
			currentNode = currentNode->next;
	}
	return currentNode;
}

void PrintLinkedList(node* start)
{
	//out<<"\nHEAD ->\n";
	while(start!=NULL)
	{
		cout<<start->data<<" ";
		start = start->next;
	}
}
void InserNodeInLinkedListAtFront(int data)
{
	//assumption:head is already defined elsewhere in the program
	//1. create the new node
	node *temp = new node;
	temp->data= data;
	//temp->next= NULL; //this line is not really needed

	//2. insert it at the first postion
	temp->next = head;

	//3. update the head to point to the new node

	temp= head;
}
void InserNodeInLinedListAtEnd(int data)
{
	//1.create the new node
	node *temp = new node;
	temp->data = data;
	temp->next=NULL;

	//check if the ilst is empty
	if(head==NULL)
	{
		head = temp;
		return;
	}
	else
	{
		//2.traverse the list till the end
		node *traveller = head;
		while(traveller->next !=NULL)
		{
			traveller = traveller->next;
		}
		//3. update the last node to point to this new node
		traveller->next = temp;
	}
}
//insert node in a random location in a list
void InsertNodeInlinedList(int data, int pos)
{
	node *temp = new node;
	temp->data = data;
	temp->next = NULL;
	//check if the postion to insert is first or the list is empty
	if((pos==1)||(head==NULL))
	{
		//set the new node to point to head
		//as th list may not be empty
		temp->next = head;

		//point head to the first node now
		head = temp;
		return;
	}
	else
	{
		//2.travers to the desire postion
		node *t = head;
		int currPos =2;
		while((currPos<pos) && (t->next !=NULL))
		{
			t = t->next;
			currPos++;
		}

		//3. now we are at the desired location
		//first set the pointer for the new node
		temp->next = t->next;
		t->next =temp;
	}
}

//delect node from the list at specified position
//return 0 if delection fails
//assumtion: head is defined elsewhere
int DelecteNode(int pos)
{
	//if the list is empty, return 0;
	if(head ==NULL)
		return 0;
	//special case: deleting first element
	if(pos==1)
	{
		//set the head to point the node
		//that head is pointing to
		head = head->next;
	}
	else
	{
		//deleting at any postion
		//travers the desired postiion
		//or still th list ends; whichever come first

		node *t=head;
		int currPos = 2;
		while((currPos<pos) && (t->next !=NULL))
		{
			t = t->next;
			currPos++;
		}
		//now come th tricky part
		//you have to point the current node to its next node
		if(t->next !=NULL)
		{
			t->next = t->next->next;
		}
		else
			return 0;
	}
	return 1;
}
int main()
{
	node head;
	head.data = 5;
	head.next = NULL;

	// Do it by hand
	node b;
	b.data = 6;
	b.next = NULL;
	head.next = &b;

	node c;
	c.data = 7;
	c.next = NULL;
	b.next = &c;

	// cout << "data: " << head.data << endl;
	// cout << "next: " << head.next << endl;
	// cout << "next data: " << head.next->data << endl;

	// node d;
	// d.data = 4;

	PrintLinkedList(&head);
	InserNodeInLinedListAtEnd(8);
	cout<<"after add 8 :"<<endl;
	PrintLinkedList(&head);


	return 0;

}