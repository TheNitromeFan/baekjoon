#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>
#define MAX 1000000000

using namespace std;

class Cmp{
	public:
		bool operator()(tuple<int, int, int> &a, tuple<int, int, int> &b){
			return get<1>(a) > get<1>(b);
		}
};

int minimum_fee(int dist[][1001], int n, int d, int sum){
	int ret = MAX;
	for(int i = 1; i < n; ++i){
		ret = min(ret, dist[d][i] + i * sum);
	}
	return ret;
}

void dijkstra(vector<vector<tuple<int, int, int>>> &adj, int dist[][1001], int s, int d){
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, Cmp> pq;
	pq.push(make_tuple(s, 0, 0));
	dist[s][0] = 0;
	while(!pq.empty()){
		tuple<int, int, int> t = pq.top();
		pq.pop();
		int u = get<0>(t), w = get<1>(t), cnt = get<2>(t);
		if(dist[u][cnt] < w){
			continue;
		}
		for(tuple<int, int, int> t1 : adj[u]){
			int v = get<0>(t1), w1 = get<1>(t1);
			if(dist[v][cnt + 1] > w + w1){
				dist[v][cnt + 1] = w + w1;
				pq.push(make_tuple(v, w + w1, cnt + 1));
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	int s, d;
	cin >> s >> d;
	vector<vector<tuple<int, int, int>>> adj(n + 1);
	for(int a0 = 0; a0 < m; ++a0){
		int a, b, w;
		cin >> a >> b >> w;
		adj[a].push_back(make_tuple(b, w, 0));
		adj[b].push_back(make_tuple(a, w, 0));
	}
	int dist[1001][1001];
	for(int i = 0; i <= 1000; ++i){
		for(int j = 0; j <= 1000; ++j){
			dist[i][j] = MAX;
		}
	}
	dijkstra(adj, dist, s, d);
	int sum = 0;
	cout << minimum_fee(dist, n, d, 0) << '\n';
	for(int a1 = 0; a1 < k; ++a1){
		int p;
		cin >> p;
		sum += p;
		cout << minimum_fee(dist, n, d, sum) << '\n';
	}
	return 0;
}
