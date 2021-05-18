#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#define MAX 1000000000

using namespace std;

class Cmp{
	public:
		bool operator()(pair<int, int> a, pair<int, int> b){
			return a.second > b.second;
		}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int n, d, c;
		cin >> n >> d >> c;
		vector<vector<pair<int, int>>> adj(n + 1);
		for(int a1 = 0; a1 < d; ++a1){
			int a, b, s;
			cin >> a >> b >> s;
			adj[b].push_back(make_pair(a, s));
		}
		vector<int> dist(n + 1, MAX);
		priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> pq;
		vector<bool> visited(n + 1);
		dist[c] = 0;
		pq.push(make_pair(c, 0));
		int ncomp = 0, fail = 0;
		while(!pq.empty()){
			pair<int, int> p = pq.top();
			pq.pop();
			int u = p.first;
			if(visited[u]){
				continue;
			}
			++ncomp;
			fail = dist[u];
			visited[u] = true;
			for(pair<int, int> q : adj[u]){
				int v = q.first, w = q.second;
				if(dist[v] > dist[u] + w){
					dist[v] = dist[u] + w;
					pq.push(make_pair(v, dist[v]));
				}
			}
		}
		cout << ncomp << ' ' << fail << '\n';
	}
	return 0;
}
