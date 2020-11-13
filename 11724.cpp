#include <cstdio>
#include <queue>

using std::queue;

int components(bool graph[][1001], int n){
	bool visited[1001];
	for(int i = 1; i <= n; ++i){
		visited[i] = false;
	}
	queue<int> q;
	int ans = 0;
	for(int i = 1; i <= n; ++i){
		if(visited[i]){
			continue;
		}
		q.push(i);
		visited[i] = true;
		++ans;
		while(!q.empty()){
			int u = q.front();
			q.pop();
			for(int v = 1; v <= n; ++v){
				if(graph[u][v] && !visited[v]){
					q.push(v);
					visited[v] = true;
				}
			}
		}
	}
	return ans;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	bool a[1001][1001];
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			a[i][j] = false;
		}
	}
	for(int a0 = 0; a0 < m; ++a0){
		int u, v;
		scanf("%d %d", &u, &v);
		a[u][v] = true;
		a[v][u] = true;
	}
	printf("%d", components(a, n));
}
