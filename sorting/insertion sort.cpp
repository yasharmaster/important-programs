#include <iostream>
#include <cstring>
#include <conio.h>

using namespace std;

void print(int A[], int size){
	for(int i=0; i<size; i++){
		cout << A[i] << "  ";
	}
}
void insertion_sort(int A[], int size){
	for(int i=1; i<size; i++){
		int hole = i;
		int value = A[i];
		while(hole > 0 && A[hole-1] > value)
			A[hole] = A[--hole];
		A[hole] = value;
	}
}

int main()
{
	cout << "Enter the size of the Array  ";
	int size;
	cin >> size;
	
	int A[size], i;
	
	for(i = 0; i<size; i++)
		cin >> A[i];
		
	print(A, size);
	
	insertion_sort(A, size);
	
	cout << endl;
	
	print(A, size);

	return 0;
}
