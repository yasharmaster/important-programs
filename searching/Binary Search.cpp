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


int binary_search(int A[], int size, int x){
	int min = 0;
	int max = size - 1;
		
	while(min <= max){
		int mid = (min + max)/2;
		
		if(A[mid] == x)
			return mid;
		else if	(A[mid] < x)
			min = mid+1;
		else
			max = mid-1;
	}
	return -1;
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
	int x;
	cout << "Enter the item you want to search  ";
	cin >> x;
	int index = binary_search(A, size, x);
	if(index == -1)
		cout << "Not Found...";
	else
		cout << "Its at index " << index;

	return 0;
}
