#include <iostream>

using namespace std;

struct Node{
	string city_name= "";
	struct Node* next = NULL;
};

Node* create_node(string city_name, struct Node* nextNode ) 
{
	struct Node* newnode = new Node;
	newnode->city_name= city_name;
	newnode->next = nextNode;
	return newnode;
}

Node* insert_node(Node* head, string city_name){
	//add the new city to head
	//if the linked of list is empty
	if(head==NULL) {
		struct Node* newnode = create_node(city_name, NULL);
		head = newnode;
	}
	else
	{
		struct Node* newnode = create_node(city_name, head);//head pointer to next node
		head = newnode;
	}
	return head;  //return new head

}
void print_list(Node* head){
	if(head==NULL){
		cout<<" empty list"<<endl;
	}
	else
	{
		Node* currentNode = head;
		while(currentNode !=NULL)
		{
			cout<< currentNode->city_name <<endl;
			currentNode = currentNode->next;
		}
	}
}
Node* insert_new_city(Node* head, string city, string new_city){
	//to check if head point equal to null
	if(head==NULL){
		cout<<"empty list"<<endl;
	}
	else
	{
		Node* tempPointer = head;
		Node* prev = NULL;
		//while(tempPointer->city_name !=city && tempPointer!=NULL)
		while(tempPointer!=NULL && tempPointer->city_name !=city && tempPointer!=NULL)
		{
			prev = tempPointer;
			tempPointer = tempPointer->next;
		}
		if(tempPointer== NULL)
		{
			cout<<"city not found"<<endl;
		}
		else
		{
			struct Node* newnode = create_node(new_city, tempPointer);
			if(tempPointer==head){
				head = newnode;
			}
			else
			{
				prev->next = newnode;
			}
		}
	}
	return head;
}

int main(int argc, char* argv[])
{
	struct Node* head = NULL;
	head = insert_node(head, "Denver");
	head = insert_node(head, "Boulder");
	head = insert_node(head, "Philly");
	print_list(head);
	
	head = insert_new_city(head, argv[1], argv[2]);
	cout<<"After add new city: "<<endl;
	print_list(head);


	return 0;
}