#ifndef LINKLIST_H
#define LINKLIST_H

class LinkList{
	private:
		struct node{
			int data;
			node *next;
		};
		typedef struct node* nodePtr;
		node *head;
		node *curr;
		node *temp;
	public:
		LinkList();
		void AddNode(int addDate);
		void DeleteNode(int delData);
		void PrintList();
};
#endif