Write C++ code that creates an integer variable called result,  dereferences a given pointer xPointer, and places that value into the variable result. The xPointer will have been declared and set to point to a value before your code runs. Your code will be placed inside the main function with all the appropriate #includes.


int result;
result = *xPointer;



Consider the following structure of node and linked list.

struct Node {
  int key;
  Node *next;
};


10 -> 20 -> 30 -> 10 -> 10 -> 50 -> 10 -> NULL



What will be the output of following pseudo-code? 
Consider head is the pointer to the first node of above 
linked list.



Node *walker = head;
int count = 0;
while(walker!= NULL && count < 3) {
        if(walker->key == 10) {
                 count = count + 1;
         }
         walker = walker->next;
}
cout <<  walker->key  << endl;

====ANSWER 50

The runtime of an algorithm is defined by the function f(n) = 3*n*log(n).
 This algorithm is bounded by O(n).

Select one:
True
False
////////////
bool found = false;
for (int i=0; !found && i<num; i++)
{
    if (i>0)
        cout << ";";
   cout << values[i];
   if (values[i] == findMe)
       found = true;
}
//////////////
