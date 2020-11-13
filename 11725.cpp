#include <cstdio>
#include <vector>
#define MAX (100000 + 1)

using namespace std;

vector<vector<int>> adj;
bool visited[MAX];
int parent[MAX];

void find_parent(int node){
	visited[node] = true;
	for(int v : adj[node]){
		if(!visited[v]){
			parent[v] = node;
			find_parent(v);
		}
	}
}

int main(){
	int n;
	scanf("%d", &n);
	adj.resize(n + 1);
	for(int i = 1; i < n; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	find_parent(1);
	for(int v = 2; v <= n; ++v){
		printf("%d\n", parent[v]);
	}
	return 0;
}
