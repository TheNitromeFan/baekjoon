#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

class Cmp{
	public:
		bool operator()(pair<int, long long> a, pair<int, long long> b){
			return a.second > b.second;
		}
};

void dijkstra(vector<vector<pair<int, int>>> &adj, vector<long long> &dist, int n, int start){
	priority_queue<pair<int, long long>, vector<pair<int, long long>>, Cmp> pq;
	vector<bool> visited(n + 1);
	dist[start] = 0;
	pq.push(make_pair(start, 0));
	while(!pq.empty()){
		pair<int, long long> p = pq.top();
		pq.pop();
		int u = p.first;
		if(visited[u]){
			continue;
		}
		for(pair<int, int> q : adj[u]){
			int v = q.first, d = q.second;
			if(dist[v] == -1 || dist[v] > dist[u] + d){
				dist[v] = dist[u] + d;
				pq.push(make_pair(v, dist[v]));
			}
		}
		visited[u] = true;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> adj(n + 1);
	for(int a0 = 0; a0 < m; ++a0){
		int u, v, w;
		cin >> u >> v >> w;
		bool found = false;
		for(pair<int, int> &p : adj[u]){
			if(p.first == v){
				p.second = min(p.second, w);
				found = true;
				break;
			}
		}
		if(!found){
			adj[u].push_back(make_pair(v, w));
		}
		found = false;
		for(pair<int, int> &p : adj[v]){
			if(p.first == u){
				p.second = min(p.second, w);
				found = true;
				break;
			}
		}
		if(!found){
			adj[v].push_back(make_pair(u, w));
		}
	}
	vector<int> yakult(10);
	for(int i = 0; i < 10; ++i){
		cin >> yakult[i];
	}
	int me;
	cin >> me;
	vector<long long> dist(n + 1, -1);
	dijkstra(adj, dist, n, me);
	int ans = -1;
	int ajumma = yakult[0];
	if(me == ajumma){
		ans = me;
	}
	long long time = 0;
	for(int i = 1; i < 10; ++i){
		vector<long long> dist1(n + 1, -1);
		dijkstra(adj, dist1, n, ajumma);
		while(i < 10 && dist1[yakult[i]] == -1){
			++i;
		}
		if(i == 10){
			break;
		}
		time += dist1[yakult[i]];
		if(dist[yakult[i]] != -1 && time >= dist[yakult[i]] && (ans == -1 || ans > yakult[i])){
			// cout << i << ' ' << yakult[i] << ' ' << time << ' ' << dist[yakult[i]] << '\n';
			ans = yakult[i];
		}
		ajumma = yakult[i];
	}
	cout << ans;
	return 0;
}
