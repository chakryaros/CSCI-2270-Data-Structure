int* CopyArray(int array[], int length, int value)
{
    int* temp = new int[length];
    bool found = false;
    int index =0;
    for(int i=0; i<length; i++)
    {
        temp[i]= array[i];
    }
    for(int i=0; i<length && !found; i++)
    {
        if(temp[i]==value)
        {
            found = true;
            index = i;
        }
    }
    if(found)
    {
        for(int i=index; i<length; i++)
        {
            temp[i]= temp[ i+1];
        }
        length = length -1;
    }
    for(int i=0; i<length; i++)
    {
        if(temp[i]==value)
        {
            for(int j=i; j<length; j++)
            {
                temp[j]= temp[j+1];
            }
            length = length -1;
        }
    }
    int *newArr = new int[length];
    for(int i=0; i<length; i++)
    {
        newArr[i]=temp[i];
    }
    delete [] temp;
    return newArr;
}