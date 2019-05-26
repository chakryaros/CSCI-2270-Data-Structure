int searchStruct(Student *StudentArray, string sname, int marks, int size)
{
    int count=0;
    for(int i=0; i<size; i++)
    {
        if(StudentArray[i].name==sname && StudentArray[i].marks > marks)
        {
            count++;
        }
    }
    return count;
}

Consider following structure of node and doubly linked list,

struct Node {

Node *prev;

int key;

Node *next;

}

Doubly linked list


temp->next = newnode;

newnode->next = temp->next;

newnode->prev = temp;

temp->next->prev = newnode;

======infinite loop====


