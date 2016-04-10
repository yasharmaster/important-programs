#include <iostream>
#include <cstring>
#include <conio.h>

using namespace std;

int partition(int A[], int start, int end){
	int pivot = A[end];
	int pIndex = start, temp;
	
	for(int i=start; i<end; i++){
		if(A[i] < pivot){
			temp = A[i];
			A[i] = A[pIndex];
			A[pIndex] = temp;
			pIndex++;
		}
	}
	temp = A[pIndex];
	A[pIndex] = pivot;
	A[end] = temp;
	return pIndex;
}

void quicksort(int A[], int start, int end){
	if(start < end){	
		int pIndex = partition(A, start, end);
		quicksort(A, start, pIndex-1);
		quicksort(A, pIndex+1, end);
	}
}

void print(int A[], int size){
	for(int i=0; i<size; i++)
		cout << A[i] << "\t";
	cout << endl;
}

int main()
{
	cout << "Enter the size of the Array  ";
	int size;
	cin >> size;
	int A[size];
	for(int i=0; i<size; i++)
		cin >> A[i];
	quicksort(A, 0, size-1);
	print(A, size);


	return 0;
}
