#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

bool bfs(vector<vector<int>> &adj, int n, int a, int b){
	queue<int> q;
	vector<bool> visited(n + 1);
	q.push(a);
	visited[a] = true;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		if(u == b){
			return true;
		}
		for(int v : adj[u]){
			if(!visited[v]){
				q.push(v);
				visited[v] = true;
			}
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<pair<int, int>> intervals(1);
	vector<vector<int>> adj(1);
	int cnt = 0;
	for(int a0 = 0; a0 < n; ++a0){
		int q;
		cin >> q;
		if(q == 1){
			int x1, y1;
			cin >> x1 >> y1;
			intervals.push_back(make_pair(x1, y1));
			++cnt;
			adj.resize(cnt + 1);
			for(int i = 1; i < cnt; ++i){
				pair<int, int> p = intervals[i];
				int x2 = p.first, y2 = p.second;
				if((x2 < x1 && x1 < y2) || (x2 < y1 && y1 < y2)){
					adj[cnt].push_back(i);
				}
				if((x1 < x2 && x2 < y1) || (x1 < y2 && y2 < y1)){
					adj[i].push_back(cnt);
				}
			}
		}else{
			int a, b;
			cin >> a >> b;
			cout << bfs(adj, n, a, b) << '\n';
		}
	}
	return 0;
}
