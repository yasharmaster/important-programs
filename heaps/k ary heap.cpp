#include <cstdio>
 
using namespace std;
 
class Heap{
public:
	int k, size;
	int *array = new int[500];
 
	Heap(int d, int s, int *a){
		k = d;
		size = s;
		for(int i=0; i<size; i++){
			array[i] = a[i];
		}
		build_heap();
	}
 
	int parent(int i){
		return (i-1)/k;
	}
 
	void build_heap(){
		for(int i =size/k; i>=0 ; i--){
			heapify(i);
		}
	}
 
	void swap(int *a, int *b){
		int temp = *a;
		*a = *b;
		*b = temp;
	}
 
	void print_size(){
		printf("size of the heap is %d\n", size);
	}
 
	void heapify(int i){
		int current = array[i];
		int child = k*i+1, max_child = -1;
		while(child < size && child<= (k)*(i+1)){
			if(current < array[child]){
				max_child = child;
				current = array[child];
			}
			child++;
		}
		if(max_child != -1){
			swap(array+i, array+max_child);
			heapify(max_child);
		}
	}
 
	void print_array(){
		for(int i=0; i<size; i++){
			printf("%d ", array[i]);
		}
		puts("");
	}
 
	int extract_max(){
		int lowest_child = array[size-1];
		size--;
		int max = array[0];
		array[0] = lowest_child;
		heapify(0);
		printf("%d extracted\n", max);
		return max;
	}
 
	void insert(int value){
		printf("%d inserted\n", value);
		size++;
		array[size-1] = value;
		int current = size-1;
		int parent = (current-1)/k;
		while(array[parent] < array[current] && parent >=0){
			swap(array + parent, array+current);
			current = parent;
			parent = (current-1)/k;
		}
	}
 
	void update(int i, int value){
		int original = array[i];
		if(value > original){
			array[i] = value;
			int parent = (i-1)/k;
			while(array[parent] < array[i] && parent >=0){
				swap(array+parent, array+ i);
				i  = parent;
				parent = (i-1)/k;
			}
		}
		else{
			array[i] = value;
			while(i < size && i != -1){	
				int max_child = -1;
				int child = i*k+1;
				value = array[i];
				while(child <= (i+1)*k && child < size ){
					if(value < array[child]){
						max_child = child;
						value = array[child];
					}
					child++;
				}
				if(max_child != -1){
					swap(array+max_child, array+i);
					i = max_child;
				}else{
					break;
				}
			}
		}
	}
 
};
 
int main(){
	printf("Enter k for k-ary heap\n");
	int k;
	scanf("%d", &k);
	puts("Enter size of the array");
	int s;
	scanf("%d", &s);
	int* a = new int[s];
	puts("Enter the elements.");
	for(int i=0; i<s;i++){
		scanf("%d", a+i);
	}
	Heap* heap = new Heap(k, s, a);
	puts("Heap Created");
	heap->print_array();
/*	int max = heap->extract_max();
	heap->print_array();
	heap->insert(5000);
	heap->insert(1);
	heap->print_array();
*/	heap->print_size();
	heap->update(9, 5000);
 
	heap->print_array();
	heap->update(0,1);
	heap->print_array();
	return 0;
}
