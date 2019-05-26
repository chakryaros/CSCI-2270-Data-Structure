void push(int value) 
{
   if(isFull()) {
       cout<<"Overflow\n";
   }
   else {
       node* newTop = new node;
       if(top==NULL) {
           newTop->value = value;
           newTop->next = NULL;
           top = newTop;
           stackCounter++;
       }
       else 
       {
           newTop->value = value;
           newTop->next = top;
           top = newTop;
           stackCounter++;
       }
   }
}


void push (int value)
{
    if(isFull())
        cout<< "Overflow"<<endl;
    else{
        node* nn = new node();
        nn->value = value;
        nn->next = top;
        top = nn;
        stackCounter++;
    }
}