#include <iostream>
#include <cstring>
#include <conio.h>

using namespace std;

void heapify(int A[], int n, int p){
	int l = 2*p + 1;
	int r = l + 1;
	int max = p;
	
	if(l < n && A[l] > A[p])
		max = l;
		
	if(r < n && A[r] > A[max])
		max = r;
	
	if(max != p){
		int temp = A[max];
		A[max] = A[p];
		A[p] = temp;
		heapify(A, n, max);
	}
}


void buildheap(int A[], int n){
	for(int i=n/2; i >= 0; i--)
		heapify(A, n, i);
}

void heapsort(int A[], int n){
	for(int i=0; i<n; i++){
		buildheap(A, n-i);
		int temp = A[0];
		A[0] = A[n-i-1];
		A[n-i-1] = temp;
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
	int n;
	cin >> n;
	int A[n];
	for(int i=0; i<n; i++)
		cin >> A[i];
	heapsort(A, n);
	print(A, n);


	return 0;
}
