#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <cstdlib>

using namespace std;

class Cmp{
	public:
		bool operator()(pair<int, int> a, pair<int, int> b){
			return a.second > b.second;
		}
};

int dijkstra(vector<vector<pair<int, int>>> &adj){
	vector<int> dist(10001, -1);
	priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> pq;
	vector<bool> visited(10001);
	dist[0] = 0;
	pq.push(make_pair(0, 0));
	while(!pq.empty()){
		pair<int, int> p = pq.top();
		pq.pop();
		int u = p.first;
		if(u == 10000){
			break;
		}else if(visited[u]){
			continue;
		}
		visited[u] = true;
		for(pair<int, int> q : adj[u]){
			int v = q.first, w = q.second;
			if(dist[v] == -1 || dist[v] > dist[u] + w){
				dist[v] = dist[u] + w;
				pq.push(make_pair(v, dist[v]));
			}
		}
	}
	return dist[10000];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<vector<pair<int, int>>> board(k + 2);
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			int x;
			cin >> x;
			board[x].push_back(make_pair(i, j));
		}
	}
	vector<vector<pair<int, int>>> adj(10001);
	for(pair<int, int> p : board[1]){
		int x = p.first, y = p.second;
		adj[0].push_back(make_pair(100 * x + y, 0));
	}
	for(int val = 1; val < k; ++val){
		for(pair<int, int> p1 : board[val]){
			int x1 = p1.first, y1 = p1.second;
			for(pair<int, int> p2: board[val + 1]){
				int x2 = p2.first, y2 = p2.second;
				adj[100 * x1 + y1].push_back(make_pair(100 * x2 + y2, abs(x1 - x2) + abs(y1 - y2)));
			}
		}
	}
	for(pair<int, int> p : board[k]){
		int x = p.first, y = p.second;
		adj[100 * x + y].push_back(make_pair(10000, 0));
	}
	cout << dijkstra(adj);
	return 0;
}
