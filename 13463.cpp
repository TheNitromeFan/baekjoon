#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int c, p, x, leave;
	cin >> c >> p >> x >> leave;
	vector<vector<int>> adj(c + 1);
	vector<unsigned> degree(c + 1);
	for(int i = 0; i < p; ++i){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		++degree[u];
		++degree[v];
	}
	queue<int> q;
	vector<bool> left(c + 1);
	q.push(leave);
	left[leave] = true;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		if(u == x){
			break;
		}
		for(int v : adj[u]){
			if(left[v]){
				continue;
			}
			--degree[v];
			if(degree[v] * 2 <= adj[v].size()){
				q.push(v);
				left[v] = true;
			}
		}
	}
	cout << (left[x] ? "leave" : "stay");
	return 0;
}
