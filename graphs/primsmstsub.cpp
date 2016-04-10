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
		for(int i =0; i<V; i++){
			printf("Node %d\t:\t", i+1);
			Edge* temp = array_edges[i];
			while(temp != NULL){
				printf(" To %d, (%d),  ", temp->destination + 1, temp->weight );
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
	
	void prims(int source){
		bool* visited = new bool[V];
		int* dist = new int[V];
		
		for(int i=0; i<V; i++){
			visited[i] = false;
			dist[i] = INT_MAX;
		}
		
		int mst_weight = 0;
		visited[source] = true;
		dist[source] = 0;
		priority_queue <node_distance, vector <node_distance>, CompareDist> pq;
		Edge* temp_edge = array_edges[source];
		while(temp_edge != NULL){
			node_distance nd(temp_edge->destination, temp_edge->weight);
			dist[temp_edge->destination] = temp_edge->weight;
			pq.push(nd);
			temp_edge = temp_edge->next;
		}
		
		while(!pq.empty()){
			node_distance nd = pq.top();
			pq.pop();
			if(visited[nd.node])
				continue;
			visited[nd.node] = true;
			mst_weight += nd.distance;
			temp_edge = array_edges[nd.node];
			while(temp_edge != NULL){
				int v = temp_edge->destination;
				int w = temp_edge->weight;
				if(!visited[v]){
					if(dist[v] > w){
						dist[v] = w;
						node_distance new_node_dist(v,w);
						pq.push(new_node_dist);
					}
				}
				temp_edge = temp_edge->next;
			}
		}
		printf("%d", mst_weight);
	}
};

int main()
{
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
	graph->prims(source-1);
	return 0;
}
