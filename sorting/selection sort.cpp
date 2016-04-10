#include <iostream>
#include <cstring>
#include <conio.h>

using namespace std;

void selection_sort(int A[], int size){
	int temp, index_of_max;
	for(int i=0; i<size; i++){
		index_of_max = i;
		for(int j = i; j<size; j++){
			if(A[j] > A[index_of_max])
				index_of_max = j;
		}
		temp = A[i];
		A[i] = A[index_of_max];
		A[index_of_max] = temp;
	}
}
void print(int A[], int size){
	for(int i=0; i<size; i++)
		cout << A[i] << "\t";
}
int main()
{
	cout << "Please enter the size of the Array	 ";
	int size;
	cin >> size;
	int A[size];
	
	cout << "Enter the numbers  ";
	
	for(int i=0; i<size; i++)
		cin >> A[i];
	
	selection_sort(A, size);
	print(A, size);
	return 0;
}
