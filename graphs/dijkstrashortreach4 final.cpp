#include <cstdio>
#include <queue>
#include <climits>

using namespace std;

class node_distance{
public:
	int node;
	int distance;
	node_distance(int a, int b){
		node = a;
		distance = b;
	}
};

class CompareDist{
public:
	bool operator()(node_distance &n1, node_distance &n2)
	{
		if(n1.distance > n2.distance)
			return true;
		else
			return false;
	}
};

class Edge{
public:
	int destination, weight;
	Edge* next;
	
	Edge(int y, int z){
		destination = y;
		weight = z;
		next = NULL;
	}
	
	void print_edge(){
		printf("%d : %d", destination, weight);
	}
};

class Graph{
public:
	int V, E;
	Edge** array_edges;
	
	Graph(int v, int e){
		E = e;
		V = v;
		array_edges = new Edge*[e];
		for(int i=0; i<e; i++){
			array_edges[i] = NULL;
		}
	}
	
	void print_edges(){
		for(int i =0; i<E; i++){
			printf("Node %d\t:\t", i+1);
			Edge* temp = array_edges[i];
			while(temp != NULL){
				printf(" To %d, (%d),\t", temp->destination + 1, temp->weight + 1);
				temp = temp->next;
			}
			puts("");
		}
	}
	
	void add_edge(int source, int dest, int weight){
		if(array_edges[source] == NULL){
			array_edges[source] = new Edge(dest, weight);
		}
		else{
			Edge* temp = array_edges[source];
			while(temp->next != NULL){
				temp = temp->next;
			}
			temp->next = new Edge(dest, weight);
		}
		
		if(array_edges[dest] == NULL){
			array_edges[dest] = new Edge(source, weight);
		}
		else{
			Edge* temp = array_edges[dest];
			while(temp->next != NULL){
				temp = temp->next;
			}
			temp->next = new Edge(source, weight);
		}
	}
	
	void dijkstra(int source){
		bool* visited = new bool[V];
		int* dist = new int[V-1];
		for(int i=0; i<V; i++){
			visited[i] = false;
			dist[i] = INT_MAX;
		}
		dist[source] = 0;
		priority_queue< node_distance, vector <node_distance>, CompareDist > pq;
		node_distance first(source, 0);
		pq.push(first);
		int count = 0;
		while(!pq.empty()){
			count++;
			node_distance nd = pq.top();
			pq.pop();
			int node = nd.node;
			int distance = nd.distance;
			if(visited[node])
				continue;
			visited[node] = true;
			Edge* temp_edge = array_edges[node];
			while(temp_edge != NULL){
				int d = temp_edge->destination;
				if(!visited[d]){
					int t = dist[node] + temp_edge->weight;
					if(dist[d] > t){
						dist[d] = t;
						node_distance any_temp_name(d,t);
						pq.push(any_temp_name);
					}
				}
				temp_edge = temp_edge->next;
			}
		}
		print_dist_array(dist, source);
	}
	
	void print_dist_array(int *dist, int source){
		for(int i = 0; i<V; i++){
			if(i != source){
				if(dist[i] == INT_MAX){
					printf("-1 ");
				}
				else{
					printf("%d ", dist[i]);
				}
			}
		}
		puts("");
	}
};

int main()
{
	int t;
	scanf("%d", &t);
	while(t--){
		int n, m;
		scanf("%d%d", &n, &m);
		Graph* graph = new Graph(n, m);
		for(int i=0; i<m; i++){
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			graph->add_edge(x-1,y-1,z);
		}
		int source;
		scanf("%d", &source);
		graph->dijkstra(source-1);
	}
	return 0;
}
