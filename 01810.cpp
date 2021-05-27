#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <utility>
#include <tuple>
#include <algorithm>
#include <queue>
#define MAX 1e18

using namespace std;

class Cmp{
	public:
		bool operator()(pair<int, double> a, pair<int, double> b){
			return a.second > b.second;
		}
};

double dist(long long x1, long long y1, long long x2, long long y2){
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

long long dijkstra(vector<vector<pair<int, double>>> &adj, vector<long long> &yc, int n, long long f){
	vector<double> dist(n + 1, MAX);
	priority_queue<pair<int, double>, vector<pair<int, double>>, Cmp> pq;
	vector<bool> visited(n + 1);
	dist[0] = 0;
	pq.push(make_pair(0, 0));
	while(!pq.empty()){
		pair<int, double> p = pq.top();
		pq.pop();
		int u = p.first;
		if(yc[u] >= f){
			return (long long)(dist[u] + 0.4999999999999999);
		}
		for(pair<int, double> q : adj[u]){
			int v = q.first;
			double d = q.second;
			if(dist[v] > dist[u] + d){
				dist[v] = dist[u] + d;
				pq.push(make_pair(v, dist[v]));
			}
		}
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	long long f;
	cin >> n >> f;
	vector<tuple<long long, long long, int>> points(n + 1);
	vector<long long> yc(n + 1);
	for(int i = 1; i <= n; ++i){
		long long x, y;
		cin >> x >> y;
		points[i] = make_tuple(x, y, i);
		yc[i] = y;
	}
	sort(points.begin(), points.end());
	vector<vector<pair<int, double>>> adj(n + 1);
	for(int i = 0; i <= n; ++i){
		long long x1 = get<0>(points[i]), y1 = get<1>(points[i]);
		int a = get<2>(points[i]);
		for(int j = i + 1; j <= n; ++j){
			long long x2 = get<0>(points[j]), y2 = get<1>(points[j]);
			int b = get<2>(points[j]);
			if(x2 - x1 > 2){
				break;
			}else if(y2 - y1 <= 2 && y2 - y1 >= -2){
				double d = dist(x1, y1, x2, y2);
				adj[a].push_back(make_pair(b, d));
				adj[b].push_back(make_pair(a, d));
			}
		}
	}
	cout << dijkstra(adj, yc, n, f);
	return 0;
}
