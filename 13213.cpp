#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define MAX 200000

using namespace std;

int bfs(vector<vector<int>> adj[2], int n){
	int dist[MAX][2];
	memset(dist, -1, sizeof(dist));
	queue<int> q;
	bool visited[MAX][2] = {};
	dist[0][0] = 0;
	q.push(0);
	q.push(0);
	visited[0][0] = true;
	dist[0][1] = 0;
	q.push(0);
	q.push(1);
	visited[0][1] = true;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		int b = q.front();
		q.pop();
		if(u == n - 1){
			return dist[u][b];
		}
		for(int v : adj[b][u]){
			if(!visited[v][!b]){
				dist[v][!b] = dist[u][b] + 1;
				q.push(v);
				q.push(!b);
				visited[v][!b] = true;
			}
		}
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, e;
	cin >> n >> e;
	vector<vector<int>> adj[2];
	adj[0].resize(n + 1);
	adj[1].resize(n + 1);
	for(int i = 0; i < e; ++i){
		int a, b, v;
		cin >> a >> b >> v;
		adj[v][a].push_back(b);
		adj[v][b].push_back(a);
	}
	cout << bfs(adj, n);
	return 0;
}
