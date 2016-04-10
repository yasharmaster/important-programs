#include <stdio.h>
#include <stdlib.h>

struct node{
	char data;
	int freq;
	struct node *left, *right;
};

struct minHeap{
	int size, capacity;
	struct node **array;
};

struct node* newNode(char data, int freq){
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->left = NULL;
	temp->right = NULL;
	temp->freq = freq;
	temp->data = data;
	return temp;
}

struct minHeap* createNewMinHeap(int capacity){
	struct minHeap* temp = (struct minHeap*)malloc(sizeof(struct minHeap));
	temp->capacity = capacity;
	temp->array = (struct node**)malloc(sizeof(struct node*)*capacity);
	temp->size = 0;
	return temp;
}

void swapNode(struct node** a, struct node** b){
	struct node* t = *a;
	*a = *b;
	*b = t;
}

void minHeapify(struct minHeap* heap, int index){
	int smallest = index;
	int left = 2*index+1;
	int right = 2*index+2;
	if(left < heap->size && heap->array[left]->freq < heap->array[smallest]){
		smallest = left;
	}
	if(right < heap->size && heap->array[right]->freq < heap->array[smallest]){
		smallest = right;
	}
	if(smallest != index){
		swap(&heap->array[index], &heap->array[smallest]);
		minHeapify(minHeap, smallest);
	}
}

int isSizeOne(struct minHeap* heap){
	return (heap->size == 1);
}

struct node* extractMin(struct minHeap* heap){
	struct node* temp = heap->array[0];
	heap->array[0] = heap->array[heap->size - 1];
	heap->size--;
	minHeapify(heap,0);
	return temp;
}

void insertNode(struct node* mynode, struct minHeap* heap){
	heap->size++;
	int i=size-1, p=(i-1)/2;
	heap->array[i] = mynode;
	while(p > 0 && heap->array[i]->freq > heap->array[p]->freq){
	//	if(heap->array[i]->freq > heap->array[p]->freq){
			swapNode(heap->array[i], heap->array[p]);
			i = p;
			p = (i-1)/2;
//		}
	}
}

void buildMinHeap(struct minHeap* heap){
	int n = heap->size - 1;
	int i;
	for( i = (n-1)/2; i>= 0; --i){
		minHeapify(heap, i);
	}
}


void print_array(int *A, int n){
	int i;
	for(i=0; i<n; i++){
		printf("%d ", A[i]);
	}
}

int isLeaf(struct node* n){
	return !(n->left) && !(n->right) ;
}

struct node* create














