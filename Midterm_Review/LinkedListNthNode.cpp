int LinkedListNthNode( node* head, int pos)
{
    node* temp = head;
    int count=0;
    int r=0;
    bool found = false;
    while(!found && temp!=NULL)
    {
        if(count==pos)
        {
            found = true;
            r = temp->value;
        }
        else
        {
            temp = temp->next;
        }
        count++;
    }
    if(found)
    {
        return r;
    }
    else
    {
        return -1;
    }
}

int LinkedListNthNode(node *head, int position)
{
    int i =0;
    for(i=0;i<position && head != NULL; i++)
    {
        head = head->next;
    }
    if(i==position)
        return head->value;
    else
        return -1;
    
}