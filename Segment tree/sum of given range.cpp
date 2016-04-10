#include <iostream>
#include <cmath>

using namespace std;

int getMid(int s, int e){
	return s+(e-s)/2;
}

int construct_st_util(int *A, int ss, int se, int *st, int node){
	if(se==ss){
		st[node] = A[ss];
		return A[ss];
	}
	int mid = getMid(ss, se);
	st[node] = construct_st_util(A, ss, mid, st, 2*node+1) + construct_st_util(A, mid+1, se, st, 2*node+2);
	return st[node];
}

int* construct_st(int *A, int n){
	int height  = (int)(ceil(log2(n)));
	int size = (int)(pow(2, height+1))-1;
	int *st = new int[size];
	construct_st_util(A, 0, n-1, st, 0);
	return st;
}

void update_value_util(int node, int ss, int se, int index, int diff, int* st){
	if(index < ss || index > se){
		return;
	}
	st[node] = st[node]+diff;
	if(se != ss){
		int mid = getMid(ss, se);
		update_value_util(2*node+1, ss, mid, index, diff, st);
		update_value_util(2*node+2, mid+1, se, index, diff, st);
	}
}

void update_value(int *A, int *st, int index, int value, int n){
	if(index<0 || index>n-1){
		return;
	}
	int diff = value-A[index];
	A[index] = value;
	update_value_util(0, 0, n-1, index, diff, st);
}

int get_sum_util(int *st, int ss, int se, int qs, int qe, int node){
	if(qs <= ss && qe >= se){
		return st[node];
	}
	if(se < qs || qe < ss){
		return 0;
	}
	int mid = getMid(ss, se);
	return get_sum_util(st, ss, mid, qs, qe, 2*node+1) + get_sum_util(st, mid+1, se, qs, qe, 2*node+2);
}

int get_sum(int *st, int n, int qs, int qe){
	if(qs > qe || qs < 0 || qe > n-1){
		return -1;
	}
	return get_sum_util(st, 0, n-1, qs, qe, 0);
}

int main(){
	int n;
	cin >> n;
	int A[n];
	for(int i=0; i<n; i++){
		cin >> A[i];
	}
	int *st = construct_st(A, n);
	int height  = (int)(ceil(log2(n)));
	int size = (int)(pow(2, height+1))-1;
	for(int i=0; i<size; i++){
		cout << st[i] << " "; 
	}
	cout << endl;
	printf("Sum of values in given range = %d\n", get_sum(st, n, 1, 3));
	update_value(A, st, 3, 51, n);
	for(int i=0; i<size; i++){
		cout << st[i] << " "; 
	}
	cout << endl;
	printf("Sum of values in given range = %d\n", get_sum(st, n, 1, 3));
	return 0;
}
