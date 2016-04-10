#include <iostream>
#include <cstring>
#include <conio.h>

using namespace std;

void bubblesort(int A[], int size){
	while(1){
		int flag = 0;
		for(int i=0; i<size-1; i++){
			if(A[i+1] < A[i]){
				int temp = A[i];
				A[i] = A[i+1];
				A[i+1] = temp;
				flag = 1; 
			}
		}
		if(flag == 0)
			break;
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
	bubblesort(A, size);
	print(A, size);
	return 0;
}
