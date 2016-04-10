#include <cstdio>
#include <climits>
#define INFINITY 5000
using namespace std;

class Graph{
public:
	int V;
	int** matrix;
	int** matrix2;
	int edge_sum=0;
	
	Graph(int v){
		V = v;
		matrix = new int*[V];
		for(int i =0; i<V; i++){
			matrix[i] = new int[V];
			for(int j=0; j<V; j++){
				matrix[i][j] = INFINITY;
			}
			matrix[i][i] = 0;
		}
	}
	
	void scan_edges(int m){
		for(int i=0; i<m; i++){
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			matrix[x-1][y-1] = z;
		}
	}
	
	void print_graph(){
		puts("Matrix 1 : ");
		for(int i =0; i<V; i++){
			printf("%d\t:\t", i+1);
			for(int j =0; j<V; j++){
				if(matrix[i][j] == INFINITY){
					printf("-1  ");
				}else{
					printf("%d  ", matrix[i][j]);
				}
			}
			puts("");
		}
	}
	
	void print_graph2(){
		puts("Matrix 2 : ");
		for(int i =0; i<V; i++){
			printf("%d\t:\t", i+1);
			for(int j =0; j<V; j++){
				if(matrix2[i][j] == INFINITY){
					printf("-1  ");
				}else{
					printf("%d  ", matrix2[i][j]);
				}
			}
			puts("");
		}
	}
	
	void floyd_warshall(){
		matrix2 = new int*[V];
		for(int i=0; i<V; i++){
			matrix2[i] = new int[V];
		}
		
		for(int i=0; i<V; i++){
			for(int j=0; j<V; j++){
				matrix2[i][j] = matrix[i][j];
			}
		}
		
	//	print_graph2();
		
		for(int k=0; k<V; k++){
	//		printf(" k = %d iteration\n", k);
			for(int i=0; i<V; i++){
				for(int j=0; j<V; j++){
					if(!(k&1)){
						matrix2[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
					}
					else{
						matrix[i][j] = min(matrix2[i][j], matrix2[i][k] + matrix2[k][j]);						
					}
				}
			}
			if(k&1){
	//			print_graph();
	//			puts("");
			}
			else{
	//			print_graph2();
	//			puts("");
			}
		}
		
		int q;
		scanf("%d", &q);
		while(q--){
			int s, d;
			scanf("%d%d", &s, &d);
			s -= 1;
			d -= 1;
			if(V&1){
				if(matrix2[s][d] == INFINITY){
					printf("-1\n");
				}
				else{
					printf("%d\n", matrix2[s][d]);
				}
			}
			else{
				if(matrix[s][d] == INFINITY){
					printf("-1\n");
				}
				else{
					printf("%d\n", matrix[s][d]);
				}
			}
		}
	}
	
	int min(int a, int b){
		return (a>b) ? b : a;
	}
};

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	Graph* graph = new Graph(n);
	graph->scan_edges(m);
//	graph->print_graph();
	
	graph->floyd_warshall();
	return 0;
}
