#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

bool bfs(vector<vector<int>> &edges, vector<int> &visited, int start){
	queue<int> q;
	visited[start] = 1;
	q.push(start);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int v : edges[u]){
			if(visited[v] == 0){
				visited[v] = visited[u] + 1;
				q.push(v);
			}else if((visited[u] - visited[v]) % 2 == 0){
				return false;
			}
		}
	}
	return true;
}

bool is_bipartite(vector<vector<int>> &edges, int n){
	vector<int> visited(n+1, 0);
	bool ret = true;
	for(int u = 1; u <= n; ++u){
		if(visited[u] == 0){
			ret = ret && bfs(edges, visited, u);
		}
	}
	return ret;
}

int main(){
	int k;
	scanf("%d", &k);
	for(int a0 = 0; a0 < k; ++a0){
		int n, m;
		scanf("%d %d", &n, &m);
		vector<vector<int>> edges;
		edges.resize(n+1);
		for(int i = 0; i < m; ++i){
			int u, v;
			scanf("%d %d", &u, &v);
			edges[u].push_back(v);
			edges[v].push_back(u);
		}
		printf("%s\n", is_bipartite(edges, n) ? "YES" : "NO");
	}
	return 0;
}
