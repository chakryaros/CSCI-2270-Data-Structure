void swap(int *a, int *b)
{
    int temp = *a;
	*a = *b;
	*b = temp;
	int i=1;
	while(i<1)
	{
	    cout<<*a <<" "<<*b<<endl;
	    i++;
	}
	
}



void swap( int *x1, int *x2 )
{
	int temp;
	temp = *x1;
	*x1 = *x2;
	*x2 = temp;
}