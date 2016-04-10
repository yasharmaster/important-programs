#include <cstdio>
#include <list>
#include <queue>

using namespace std;

class Graph
{
public:
	list<int> *adj;
	int V;
	Graph(int V){
		this->V= V;
		adj = new list<int>[V];
	}
	~Graph(){
		for(int i=0; i<V; i++){
			adj[i].clear();
		}
	//	delete adj;
	}
	
	void addEdge(int v, int w){
		adj[v].push_back(w);
	}
	
	void BFS(int s){
		int level[V];
		for(int i=0; i<V; i++){
			level[i] = -1;
		}
		queue<int> q;
		level[s] = 0;
		q.push(s);
		
		list<int>::iterator k;
		
		while(!q.empty()){
			int s = q.front();
			q.pop();
			for(k=adj[s].begin(); k!= adj[s].end(); ++k){
				if(level[*k] == -1){
					level[*k] = 1 + level[s];
					q.push(*k);
				}
			}
		}
		
		for(int i=0; i<V; i++){
			if(level[i] !=0){
				if(level[i] != -1){
					printf("%d ", level[i]*6);
				}
				else
					printf("%d ", level[i]);
			}
		}
		puts("");
	}
	
	void print(){
		puts("\n*******************\n");
		for(int i =0; i<V ;i++){
			printf("%d : ", i+1);
			list<int>::iterator j;
			for(j=adj[i].begin(); j != adj[i].end(); ++j){
				printf("%d ", *j+1);
			}
			puts("");
		}
		puts("\n*******************\n");
	}
};

int main()
{
	int t;
	scanf("%d", &t);
	while(t--){
		int n, m;
		scanf("%d%d", &n, &m);
		
		Graph* g = new Graph(n);
		for(int i=0; i<m; i++){
			int x, y;
			scanf("%d%d", &x,&y);
			g->addEdge(x-1,y-1);
			g->addEdge(y-1,x-1);
		} 
		int s;
		scanf("%d", &s);
		g->BFS(s-1);
		delete g;		
	}
	
	return 0;
}


