#include <iostream>

using namespace std;

struct node {
	int key;
	node* next;
};

// node* AddNode(node* head, int num)
// {
//     node* temp = new node;
//     temp->key = num;
//     temp->next = NULL;
//     if(head==NULL)
//     {
//         head = temp;
//         return head;
//     }
//     else{
//         node* last = head;
//         while(last->next!=NULL)
//         {
//             last = last->next;
//         }
//         last->next = temp;
//     }
//     return head;
// }

// node * AddNode(node *head, int key) {
// 	node *current = head;
// 	node *prev = NULL;
// 	while (current != NULL) {
// 		prev = current;
// 		current = current->next;
// 	}

// 	current = new node;
// 	current->key = key;
// 	current->next = NULL;
// 	prev->next = current;
// 	return head;
// }
node* AddNode(node* head, int v)
{
	node* current = new node;
	current->key = v;
	current->next = NULL;
	if(head==NULL)
	{
		head = current;
		return head;
	}
	else
	{
		node* temp = head;
		while(temp->next!=NULL)
		{
			temp = temp->next;
		}
		temp->next = current;
	}
	return head;
}


int findNodeMin(node* head)
{
	node* current = head;
	int min = current->key;
	while(current!=NULL)
	{
		if(current->key < min)
		{
			min = current->key;
		}
		current = current->next;
	}
	return min;
	//cout<<"min"<< min<<endl;
}

int findNodeMax(node* head)
{
	node* current = head;
	int max = current->key;
	while(current!=NULL)
	{
		if(current->key> max)
		{
			max = current->key;
		}
		current=current->next;
	}
	return max;
}

node* searchNode(node* head, int v)
{
	node* temp = head;
	node* returnNode = NULL;
	bool found = false;
	while(!found && temp!=NULL)
	{
		if(temp->key==v)
		{
			found = true;
			returnNode = temp;
		}
		else
		{
			temp = temp->next;
		}
	}
	if(found)
		return returnNode;
}

void traverse(node* head){
	node* temp = head;
	while(temp!=NULL){
		cout<<temp->key<<", ";
		temp = temp->next;
	}
	cout<< endl;
}

int LinkedListNthNode(node *head, int position)
{
    node* current = head;
    int count =0;
    bool found = false;
    while(!found && current!=NULL)
    {
        if(count==position)
        {
            found = true;
        }
        else {
            current = current->next;
        }
        count++;
    }
    if(found)
    {
        return current->key;
    }
    else
    {
        return -1;
    }
}

void ReverseLinkedList(node* head) {
	node* c = head;

	node* prev = NULL;
	while(c !=NULL) {
		node* next = c->next;
		c->next = prev;

		prev = c;
		c = next;
	}
	//return prev;
}

int main()
{
	int*p;
	p = new int;
	*p = 100;
	//cout <<"P:"<<p<<endl;
	
	int *d = new int(100);
	//cout<<"d:"<<*d<<endl;
	
	int *h = NULL;
	h = new int;
	*h=100;

	node head;
	head.key = 10;
	head.next = NULL;
	AddNode(&head, 7);
	AddNode(&head, 5);
	AddNode(&head, 6);
	AddNode(&head, 9);
	AddNode(&head, 12);
	AddNode(&head, 92);
	// insert(33, &head, );
	traverse(&head);
	//ReverseLinkedList(&head);
	traverse(&head);
	cout<<"min:"<<findNodeMin(&head)<<endl;
	cout<<"max:"<<findNodeMax(&head)<<endl;
	//cout<<"search: "<<searchNode(&head, 9)<<endl;
	int output=LinkedListNthNode(&head, 0);
	cout<<"index at 0: "<<output;
	

}