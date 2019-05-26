#include<iostream>

using namespace std;

struct singleNode {
	int key;
	singleNode* next;
};

struct  doubleNode {
	int key;
	doubleNode* next;
	doubleNode* prev;
};

class LinkedList {
	private:
		singleNode* head;
	public:
		LinkedList(singleNode* h)
		{
			head = h;
		}
		void travese()
		{
			singleNode* temp = head;
			while(temp!=NULL)
			{
				cout <<temp->key <<" ";
				temp = temp->next;
			}
			cout<<endl;
		}
		singleNode* searchNode(int value) {
			singleNode* temp = head;
			singleNode* returnNode = NULL;
			bool found = false;
			while(!found && temp!=NULL) {
				if(temp->key==value)
				{
					found = true;
					returnNode = temp;
				} else {
					temp = temp->next;
				}
			}
			return returnNode;
		}
		void insertNode(int* leftValue, int value) {
			singleNode* newNode = new singleNode;
			newNode->key = value;
			//newNode->next=NULL;
			if(leftValue==NULL)
			{
				newNode->next = head;
				head = newNode;
			}
			else {
				singleNode* temp = head;
				while(temp->key!=*leftValue) {
					temp = temp->next;
				}
				newNode->next = temp->next;
				temp->next = newNode;
			}
		}
		void deleteNode(int value) {
			if(head->key==value) {
				singleNode* temp = head;
				head = temp->next;
				temp->next = NULL;
					// or temp->next = NULL
			} else {
				singleNode* temp = head;
				while(temp->next->key !=value) {
					temp = temp->next;
				}
				singleNode* deleting = temp->next;
				temp->next = temp->next->next;
				deleting->next =NULL;
			}
		}
};

int main()
{
	singleNode* h;
	h->key = 5;
	h->next =NULL;
	int value =5;
	int* leftValue = &value;

	 LinkedList list(h);
	 list.insertNode(leftValue, 6);
	 list.insertNode(leftValue, 7);
	 list.insertNode(leftValue, 8);
	 list.insertNode(leftValue, 9);
	 list.travese();
	 //cout<<"After delete: "<<endl;
	 list.deleteNode(9);
	 list.deleteNode(5);
	 list.travese();
	 return 0;
}