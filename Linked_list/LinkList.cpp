//#include <cstdlib>
#include<iostream>

#include "LinkList.h"

using namespace std;

LinkList::LinkList(){
	head = NULL;
	curr = NULL;
	temp = NULL;
}
void LinkList::AddNode(int addDate){
	node *n = new node;
	n->next = NULL; //find the next node
	n->data = addDate;
	if(head!= NULL){
		curr = head;
		//to check end of list
		while(curr->next !=NULL)
		{
			curr = curr->next;
		}
		curr->next = n;
	}
	else
	{
		head = n;
	}
}
void LinkList::DeleteNode(int delDate){
	node * delPtr = NULL;
	temp = head;
	curr = head;
	while(curr !=NULL && curr->data != delDate){
		temp = curr;
		curr = curr->next;
	}
	if(curr == NULL){
		cout<< delDate << " was not in the list\n";
		delete delPtr;
	}
	else
	{
		delPtr = curr;
		curr = curr->next;
		temp->next = curr;
		if(delPtr ==head)
		{
			head = head->next;
			temp = NULL;
		}
		delete delPtr;
		cout<<"The value "<< delDate <<" was deleted\n";
	}
	// City* deleleCity = head;  //declare new city for delete
	// City* temp = new City;
	// if(deleleCity->cityName == removeCity)	//if the city name find;
	// {
	// 	head = deleleCity->next;		//set head to next city
	// 	deleleCity->next=NULL;	//delect cityname
	// 	head->previous =NULL;
	// }
	// else
	// {
	// 	temp = head;
	// 	while(temp !=NULL && temp->next->cityName != removeCity) //loop for find the cityname
	// 	{
	// 		// if(temp->next==NULL)
	// 		// {
	// 		// 	cout<<removeCity<<" not found"<<endl;
	// 		// 	return;
	// 		// }
	// 		temp = temp->next;
	// 	}
	// 	if(temp==NULL)
	// 	{
	// 		cout<<removeCity<<" not found"<<endl;
	// 		return;
	// 	}
	// 	else {

	// 		City* deleting = temp->next;
	// 		temp->next = deleting->next;
	// 		deleting->next = NULL;
	// 		deleting->previous=NULL;	
	// 	}
	// }
}
void LinkList::PrintList(){
	curr = head;
	while(curr != NULL) // node pointer to somewhere in list
	{
		cout<< curr->data<< endl;
		curr = curr->next;
	}
}