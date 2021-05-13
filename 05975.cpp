#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int currents(vector<vector<int>> &adj, int n, int start, vector<vector<int>> &times){
	queue<int> q;
	vector<int> visited(n + 1, -1);
	q.push(start);
	visited[start] = 0;
	times[0].push_back(start);
	int max_time = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int v : adj[u]){
			if(visited[v] != -1){
				continue;
			}
			q.push(v);
			visited[v] = visited[u] + 1;
			times[visited[v]].push_back(v);
			max_time = visited[v];
		}
	}
	return max_time;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			int x;
			cin >> x;
			if(x){
				adj[i].push_back(j);
			}
		}
	}
	vector<vector<int>> times(110);
	int max_time = currents(adj, n, m, times);
	for(int time = 0; time <= max_time; ++time){
		sort(times[time].begin(), times[time].end());
		for(int v : times[time]){
			cout << v << ' ';
		}
		cout << '\n';
	}
	return 0;
}
