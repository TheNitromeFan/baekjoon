#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#define MAXN 310
#define MAXF 2000000000

using namespace std;

bool on_line(pair<int, int> a, pair<int, int> b, pair<int, int> p){
	int ax = a.first, ay = a.second, bx = b.first, by = b.second, px = p.first, py = p.second;
	return (py == ay && py == by && ((px >= ax && px <= bx) || (px >= bx && px <= ax)))
	|| (px == ax && px == bx && ((py >= ay && py <= by) || (py >= by && py <= ay)));
}

int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c){
	int ax = a.first, ay = a.second, bx = b.first, by = b.second, cx = c.first, cy = c.second;
	long long cmp = (long long)(bx - ax) * (cy - ay) - (long long)(cx - ax) * (by - ay);
	if(cmp > 0){
		return 1;
	}else if(cmp < 0){
		return -1;
	}else{
		return 0;
	}
}

bool disjoint(int a, int b, int c, int d){
	if(a > b){
		swap(a, b);
	}
	if(c > d){
		swap(c, d);
	}
	return b < c || d < a;
}

bool intersect(pair<int, int> a, pair<int, int> b, pair<int, int> c, pair<int, int> d){
	int cmp1 = ccw(a, b, c) * ccw(a, b, d);
	int cmp2 = ccw(c, d, a) * ccw(c, d, b);
	if(cmp1 == 0 && cmp2 == 0){
		return !disjoint(a.first, b.first, c.first, d.first) && !disjoint(a.second, b.second, c.second, d.second);
	}
	return cmp1 <= 0 && cmp2 <= 0;
}

bool can_reach(vector<pair<int, int>> &points, pair<int, int> hole, pair<int, int> mouse, int n){
	for(int i = 0; i < n; ++i){
		pair<int, int> p1 = points[i], p2 = points[i + 1];
		if(on_line(p1, p2, hole)){
			continue;
		}
		if(intersect(mouse, hole, p1, p2)){
			return false;
		}
	}
	return true;
}

bool bfs(vector<vector<int>> &adj, int c[][MAXN], int f[][MAXN], vector<int> &prev, int src, int dest){
	queue<int> q;
	q.push(src);
	prev[src] = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		if(u == dest){
			return true;
		}
		for(int v : adj[u]){
			if(c[u][v] > f[u][v] && prev[v] == -1){
				q.push(v);
				prev[v] = u;
			}
		}
	}
	return false;
}

int edmonds_karp(vector<vector<int>> &adj, int c[][MAXN], int sz, int src, int dest){
	int f[MAXN][MAXN] = {};
	int max_flow = 0;
	while(true){
		vector<int> prev(sz, -1);
		if(!bfs(adj, c, f, prev, src, dest)){
			break;
		}
		int v = dest;
		int flow = MAXF;
		while(v != src){
			int u = prev[v];
			flow = min(flow, c[u][v] - f[u][v]);
			v = u;
		}
		v = dest;
		while(v != src){
			int u = prev[v];
			f[u][v] += flow;
			f[v][u] -= flow;
			v = u;
		}
		max_flow += flow;
	}
	return max_flow;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k, h, m;
	cin >> n >> k >> h >> m;
	vector<pair<int, int>> points(n), holes(h), mice(m);
	for(int i = 0; i < n; ++i){
		int x, y;
		cin >> x >> y;
		points[i] = make_pair(x, y);
	}
	for(int j = 0; j < h; ++j){
		int x, y;
		cin >> x >> y;
		holes[j] = make_pair(x, y);
	}
	for(int l = 0; l < m; ++l){
		int x, y;
		cin >> x >> y;
		mice[l] = make_pair(x, y);
	}
	vector<vector<int>> adj(m + h + 2);
	int cap[MAXN][MAXN] = {};
	points.push_back(points[0]);
	for(int l = 0; l < m; ++l){
		for(int j = 0; j < h; ++j){
			if(can_reach(points, holes[j], mice[l], n)){
				adj[l].push_back(m + j);
				adj[m + j].push_back(l);
				cap[l][m + j] = MAXF;
			}
		}
	}
	for(int l = 0; l < m; ++l){
		adj[m + h].push_back(l);
		adj[l].push_back(m + h);
		cap[m + h][l] = 1;
	}
	for(int j = 0; j < h; ++j){
		adj[m + j].push_back(m + h + 1);
		adj[m + h + 1].push_back(m + j);
		cap[m + j][m + h + 1] = k;
	}
	cout << (edmonds_karp(adj, cap, m + h + 2, m + h, m + h + 1) == m ? "Possible\n" : "Impossible\n");
	return 0;
}
