#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int perimeter(int x, int y){
	return 2 * (x + y);
}

void traverse(vector<pair<int, int>> &map, vector<vector<int>> &adj, vector<bool> &visited, int start, int &minX, int &maxX, int &minY, int &maxY){
	queue<int> q;
	q.push(start);
	visited[start] = true;
	minX = map[start].first;
	maxX = map[start].first;
	minY = map[start].second;
	maxY = map[start].second;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int v : adj[u]){
			if(!visited[v]){
				q.push(v);
				visited[v] = true;
				minX = min(minX, map[v].first);
				maxX = max(maxX, map[v].first);
				minY = min(minY, map[v].second);
				maxY = max(maxY, map[v].second);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> cows(n + 1);
	for(int i = 1; i <= n; ++i){
		cin >> cows[i].first >> cows[i].second;
	}
	vector<vector<int>> adj(n + 1);
	for(int j = 0; j < m; ++j){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<bool> visited(n + 1);
	int smallest_perimeter = 1000000000;
	for(int u = 1; u <= n; ++u){
		if(!visited[u]){
			int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
			traverse(cows, adj, visited, u, x1, x2, y1, y2);
			smallest_perimeter = min(smallest_perimeter, perimeter(x2 - x1, y2 - y1));
		}
	}
	cout << smallest_perimeter;
	return 0;
}
