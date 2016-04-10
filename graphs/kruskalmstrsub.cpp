#include <cstdio>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int compare_edges(const void* a, const void* b);

class Edge{
	public:
		int source, destination, weight;
};

class Node{
	public:
		int name;
		Node* label;
		Node(int n, Node* l){
			name = n;
			label = l;
		}
};

class Graph{
	public:
		int V, E;
		Edge* array;
		int* size;
		Node** root;
		Node** node;
		
		Graph(int a, int b){
			V = a;
			E = b;
			array = new Edge[b];
			size = new int[V];
			root = new Node*[V];
			node = new Node*[V]; 
			for(int i=0; i<V; i++){
				size[i] = 1;
				Node* temp = new Node(i+1, NULL);
				temp->label = temp;
				root[i] = temp;
				node[i] = temp;
			}
		}
		
		void add_edge(int x, int y, int z, int i){
			array[i].source= x;
			array[i].destination= y;
			array[i].weight= z;
		}
		
		int find_component(int nm){
			Node* parent;
			Node* temp;
			Node* t;
			temp = node[nm-1];
			if(temp->label == temp){
				return nm;
			}
			else if (temp->label->label != temp->label){
				while(temp->label != temp){
					temp = temp->label;
				}
				parent = temp;
				temp = node[nm-1];
				while(temp->label != temp){
					t = temp;
					temp = temp->label;
					t->label = parent;
				}
			}
			return temp->label->name;
		}
		
		void union_components(int x, int y){
			int a = find_component(x), b = find_component(y);
			if(size[a-1]>size[b-1]){
				node[b-1]->label = node[a-1];
				size[a-1] += size[b-1];
				size[b-1] = -1;
			}
			else if(size[a-1]<=size[b-1]){
				node[a-1]->label = node[b-1];
				size[b-1] += size[a-1];
				size[a-1] = -1;
			}
		}
		
		void kruskal(){
			qsort(array, E, sizeof(array[0]), compare_edges);
		/*	puts("");
			for(int i=0; i<E; i++){
				printf("%d ", array[i].weight);
			}
			puts("");
		*/	int ans = 0;
			for(int i=0; i<E; i++){
				int u = array[i].destination;
				int v = array[i].source;
				
				if(find_component(u) != find_component(v)){
					ans += array[i].weight;
					union_components(u, v);
				}
			}
			printf("%d", ans);
		}
};

int compare_edges(const void* a, const void* b){
	Edge* a1 = (Edge*)a;
	Edge* b1 = (Edge*)b;
	return  ((a1->weight > b1->weight) ? 1 : 0 );
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	Graph* graph = new Graph(n, m);
	int s, d, w;
	for(int i=0; i<m; i++){
		scanf("%d%d%d", &s, &d, &w);
		graph->add_edge(s,d,w,i);
	}
	scanf("%d", &s);
	graph->kruskal();
	return 0;
}
