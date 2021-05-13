#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <functional>

using namespace std;

void dijkstra(vector<priority_queue<int>> &heap, vector<vector<pair<int, int>>> &adj, unsigned k){
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, 1));
	heap[1].push(0);
	while(!pq.empty()){
		pair<int, int> p = pq.top();
		pq.pop();
		int cost = p.first, u = p.second;
		// cout << u << '\n';
		for(pair<int, int> q : adj[u]){
			int v = q.first, new_cost = cost + q.second;
			if(heap[v].size() < k){
				pq.push(make_pair(new_cost, v));
				heap[v].push(new_cost);
			}else if(heap[v].top() > new_cost){
				heap[v].pop();
				pq.push(make_pair(new_cost, v));
				heap[v].push(new_cost);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	unsigned k;
	cin >> n >> m >> k;
	vector<vector<pair<int, int>>> adj(n + 1);
	for(int i = 0; i < m; ++i){
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back(make_pair(b, c));
	}
	vector<priority_queue<int>> heap(n + 1);
	dijkstra(heap, adj, k);
	for(int v = 1; v <= n; ++v){
		if(heap[v].size() == k){
			cout << heap[v].top() << '\n';
		}else{
			cout << -1 << '\n';
		}
	}
	return 0;
}
