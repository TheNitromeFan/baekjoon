#include <cstdio>
#include <vector>
#define MAX (10000 + 1)

using namespace std;

void dfs(vector<int> adj[MAX], int hacked[MAX], bool visited[MAX], int src){
	visited[src] = true;
	++hacked[src];
	for(int v : adj[src]){
		if(!visited[v]){
			dfs(adj, hacked, visited, v);
		}
	}
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> adj[MAX];
	for(int i = 0; i < m; ++i){
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
	}
	int can_hack[MAX] = {};
	for(int u = 1; u <= n; ++u){
		bool visited[MAX] = {};
		dfs(adj, can_hack, visited, u);
	}
	vector<int> ans;
	int max_infected = 0;
	for(int u = 1; u <= n; ++u){
		if(can_hack[u] == max_infected){
			ans.push_back(u);
		}else if(can_hack[u] > max_infected){
			max_infected = can_hack[u];
			ans.clear();
			ans.push_back(u);
		}
	}
	for(int v : ans){
		printf("%d ", v);
	}
	return 0;
}
