#include <cstdio>
#include <vector>
#include <utility>
#include <tuple>
#include <map>
#include <limits>
#define MAX 30

using namespace std;

void add_edge(vector<tuple<pair<int, int>, pair<int, int>, int>> &adj, pair<int, int> start, pair<int, int> end, int weight){
	for(auto &edge : adj){
		if(get<0>(edge) == start && get<1>(edge) == end){
			if(get<2>(edge) > weight){
				get<2>(edge) = weight;
			}
			return;
		}
	}
	adj.push_back(make_tuple(start, end, weight));
}

void bellman_ford(vector<tuple<pair<int, int>, pair<int, int>, int>> &adj, int n, int m){
	map<pair<int, int>, int> dist;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			dist[make_pair(i, j)] = numeric_limits<int>::max();
		}
	}
	dist[make_pair(0, 0)] = 0;
	for(int i = 0; i < n * m - 1; ++i){
		for(auto &edge : adj){
			auto u = get<0>(edge), v = get<1>(edge);
			int w = get<2>(edge);
			if(dist[v] > dist[u] + w){
				dist[v] = dist[u] + w;
			}
		}
	}
	for(auto &edge : adj){
		auto u = get<0>(edge), v = get<1>(edge);
		int w = get<2>(edge);
		if(dist[v] > dist[u] + w){
			printf("Never\n");
			return;
		}
	}
	int ans = dist[make_pair(n - 1, m - 1)];
	if(ans == numeric_limits<int>::max()){
		printf("Impossible\n");
	}else{
		printf("%d\n", ans);
	}
}

int main(){
	while(true){
		int n, m;
		scanf("%d %d", &n, &m);
		if(n == 0 && m == 0){
			break;
		}
		vector<tuple<pair<int, int>, pair<int, int>, int>> adj;
		int g;
		scanf("%d", &g);
		int ma[MAX][MAX] = {};
		for(int i = 0; i < g; ++i){
			int x, y;
			scanf("%d %d", &x, &y);
			ma[x][y] = 1;
		}
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				if(ma[i][j] == 1){
					continue;
				}
				if(i > 0 && ma[i - 1][j] != 1){
					add_edge(adj, make_pair(i, j), make_pair(i - 1, j), 1);
				}
				if(i < n - 1 && ma[i + 1][j] != 1){
					add_edge(adj, make_pair(i, j), make_pair(i + 1, j), 1);
				}
				if(j > 0 && ma[i][j - 1] != 1){
					add_edge(adj, make_pair(i, j), make_pair(i, j - 1), 1);
				}
				if(j < m - 1 && ma[i][j + 1] != 1){
					add_edge(adj, make_pair(i, j), make_pair(i, j + 1), 1);
				}
			}
		}
		int e;
		scanf("%d", &e);
		for(int i = 0; i < e; ++i){
			int x1, y1, x2, y2, t;
			scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &t);
			ma[x1][y1] = 2;
			add_edge(adj, make_pair(x1, y1), make_pair(x2, y2), t);
		}
		bellman_ford(adj, n, m);
	}
	return 0;
}
