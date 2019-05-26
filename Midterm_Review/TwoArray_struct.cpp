TwoArray* populateStruct(string Arr1[], int Arr2[], int size)
{
    TwoArray* temp = new TwoArray[size];
    for(int i=0; i<size; i++)
    {
        temp[i].a1 = Arr1[i];
        temp[i].a2 = Arr2[i];
    }
    return temp;
}