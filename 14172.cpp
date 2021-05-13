#include <iostream>
#include <vector>
#include <queue>
#define MAX 210

using namespace std;

struct cow{
	int x;
	int y;
	int p;
} cows[MAX];

int bfs(vector<vector<int>> &adj, int n, int start){
	queue<int> q;
	vector<bool> visited(n);
	q.push(start);
	visited[start] = true;
	int ret = 1;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int v : adj[u]){
			if(!visited[v]){
				q.push(v);
				visited[v] = true;
				++ret;
			}
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> cows[i].x >> cows[i].y >> cows[i].p;
	}
	vector<vector<int>> adj(n);
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(i != j && (cows[i].x - cows[j].x) * (cows[i].x - cows[j].x)
			+ (cows[i].y - cows[j].y) * (cows[i].y - cows[j].y)
			<= cows[i].p * cows[i].p){
				adj[i].push_back(j);
				// cout << j << ' ' << i << '\n';
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < n; ++i){
		int cmp = bfs(adj, n, i);
		if(ans < cmp){
			ans = cmp;
		}
	}
	cout << ans;
	return 0;
}
