# include <iostream>

using namespace std;

int insertArrayElement(int A[], int v, int index, int numElements){
	for(int x = numElements-1; x>= index; x--){
		A[x+1] = A[x];
	}
	A[index] = v;
	numElements++;

	return 0;
}

int* doubleArray(int A[], int numElements){
	int B[] = new int[numElements*2];

	for(int i = 0; i < numElements; i++){
		B[i] = A[i];
	}

	delete A;
	return B;
}

int main(){
	int Array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int value = 10;
	int numElements = 10;

	cout << "Inserting an Array Element:";

	cout << "Before: (";
	for(int i = 0; i < numElements; i++){
		cout << Array[i] << ", ";
	}
	cout << ")" << endl;

	int new_index = 7;
	insertArrayElement(Array, value, new_index, numElements);

	cout << "After: (";
	for(int i = 0; i < numElements; i++){
		cout << Array[i] << ", ";
	}
	cout << ")" << endl;

	cout << endl;

	cout << "Doubling the size of an array:";

	cout << "Before: (";
	for(int i = 0; i < numElements; i++){
		cout << Array[i] << ", ";
	}
	cout << ")" << endl;

	int* B = doubleArray(Array, numElements);

	cout << "After: (";
	for(int i = 0; i < numElements; i++){
		cout << B[i] << ", ";
	}
	cout << ")" << endl;

	return 0;
}