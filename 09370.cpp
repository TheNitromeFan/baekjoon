#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

class Cmp{
	public:
		bool operator() (pair<int, int> a, pair<int, int> b){
			return a.second > b.second;
		}
};

vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int start){
	vector<int> dist(adj.size(), -1);
	dist[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> pq;
	pq.push(make_pair(start, 0));
	while(!pq.empty()){
		auto p = pq.top();
		pq.pop();
		int u = p.first;
		for(auto &tmp : adj[u]){
			int v = tmp.first, d = tmp.second;
			if(dist[v] == -1 || dist[v] > dist[u] + d){
				dist[v] = dist[u] + d;
				pq.push(make_pair(v, d));
			}
		}
	}
	return dist;
}

int main(){
	int tc;
	scanf("%d", &tc);
	for(int a0 = 0; a0 < tc; ++a0){
		int n, m, t, s, g, h;
		scanf("%d %d %d\n%d %d %d", &n, &m, &t, &s, &g, &h);
		vector<vector<pair<int, int>>> adj;
		adj.resize(n + 1);
		int w;
		for(int i = 0; i < m; ++i){
			int a, b, d;
			scanf("%d %d %d", &a, &b, &d);
			adj[a].push_back(make_pair(b, d));
			adj[b].push_back(make_pair(a, d));
			if((a == g && b == h) || (a == h && b == g)){
				w = d;
			}
		}
		vector<int> cand(t, 0);
		for(int i = 0; i < t; ++i){
			scanf("%d", &cand[i]);
		}
		vector<int> initial = dijkstra(adj, s);
		int g_to_s = initial[g], h_to_s = initial[h];
		vector<int> ans;
		for(int x : cand){
			vector<int> final = dijkstra(adj, x);
			int x_to_g = final[g], x_to_h = final[h], x_to_s = final[s];
			if((x_to_g < x_to_h && x_to_g + w == x_to_h && x_to_h + h_to_s == x_to_s) 
			|| (x_to_g >= x_to_h && x_to_h + w == x_to_g && x_to_g + g_to_s == x_to_s)){
				ans.push_back(x);
			}
		}
		sort(ans.begin(), ans.end());
		for(int x : ans){
			printf("%d ", x);
		}
		printf("\n");
	}
	return 0;
}
