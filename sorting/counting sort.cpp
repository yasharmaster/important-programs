#include <iostream>
#include <cstring>
#include <conio.h>

using namespace std;

void counting_sort(int A[], int size, int min, int max){
	int count[max-min+1];
	for(int x=0; x<max-min+1; x++)
		count[x] = 0;
	for(int i=0; i<size; i++){
		count[A[i]-min]++;		
	}
	int k=0;
	for(int i = 0; i<=max-min; i++){
		while(count[i]--){
			A[k++] = i+min;
		}
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
	cout << "Please enter the Minimum & the Maximum element of the Array  ";
	int min, max;
	cin >> min >> max;
	int A[size];
	cout << "Enter the numbers  ";
	for(int i=0; i<size; i++)
		cin >> A[i];		
	counting_sort(A, size, min, max);
	print(A, size);
	return 0;
}
