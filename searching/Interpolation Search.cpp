#include <iostream>


using namespace std;

int binary_s(int A[], int size, int x, int min, int max){
		
	while(min < max){
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

int interpolation_search(int A[], int size, int x){
	int distance = x - A[0];
	int values_range = A[size-1] - A[0];
	float fraction = distance/float(values_range);
	
	int index_range = size;
	int estimate = fraction*size;
//	cout << "estimate is " << estimate << endl;
	if(A[estimate] == x)
		return estimate;
	int minimum, max;
	if(A[estimate] < x){
		minimum = estimate;
		int i=1;
		while(A[estimate + i] < x && estimate + i < size){
			if(A[estimate + i] == x)
				return estimate+i;
			i *= 2;
		}
		max = estimate + i;
//		cout << "block 1 executed\n";
	}
	else {
		max = estimate;
		int i=1;
		while(A[estimate-i] < x && estimate - i >= 0){
			if(A[estimate-i] == x)
				return estimate-i;
			i *= 2;
		}
		minimum = estimate - i;
//		cout << "block 2 executed\n";
	}
	
	return binary_s(A, size, x, minimum, max);
}


int main()
{
	
	cout << "Enter the size of the Array  ";
	int size;
	cin >> size;
	
	int A[size];
	for(int i=0; i<size; i++)
		cin >> A[i];		

	int x;
	cout << "Enter the item you want to search  ";
	cin >> x;
	
	int index = interpolation_search(A, size, x);
	
	if(index == -1)
		cout << "Not Found...";
	else
		cout << "Its at index " << index;
	
	return 0;
}
