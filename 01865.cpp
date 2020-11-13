#include <cstdio>
#include <vector>
#include <tuple>
#define MAX (10000 * 500 + 1)

using namespace std;

void add_edge(vector<tuple<int, int, int>> &adj, int start, int end, int weight){
	for(auto &tmp : adj){
		if(get<0>(tmp) == start && get<1>(tmp) == end){
			if(get<2>(tmp) > weight){
				get<2>(tmp) = weight;
			}
			return;
		}
	}
	adj.push_back(make_tuple(start, end, weight));
}

bool bellman_ford(vector<tuple<int, int, int>> &adj, int n, int src){
	vector<int> dist(n + 1, MAX);
	dist[src] = 0;
	for(int i = 0; i < n - 1; ++i){
		for(auto &edge : adj){
			int u = get<0>(edge), v = get<1>(edge), w = get<2>(edge);
			if(dist[u] != MAX && (dist[v] == MAX || dist[v] > dist[u] + w)){
				dist[v] = dist[u] + w;
			}
		}
		/*
		for(int i = 1; i <= n; ++i){
			printf("%d ", dist[i]);
		}
		printf("\n");
		*/
	}
	for(auto &edge : adj){
		int u = get<0>(edge), v = get<1>(edge), w = get<2>(edge);
		if(dist[u] != MAX && (dist[v] == MAX || dist[v] > dist[u] + w)){
			return true;
		}
	}
	return false;
}

int find_parent(vector<int> &parent, int x){
	if(parent[x] != x){
		parent[x] = find_parent(parent, parent[x]);
	}
	return parent[x];
}

void merge(vector<int> &parent, int x, int y){
	int px = find_parent(parent, x), py = find_parent(parent, y);
	if(px != py){
		parent[px] = py;
	}
}

bool has_cycle(vector<tuple<int, int, int>> &adj, vector<int> &parent, int n){
	/*
	for(int i = 1; i <= n; ++i){
		if(bellman_ford(adj, n, i)){
			return true;
		}
	}
	return false;
	*/
	vector<bool> components(n + 1, false);
	for(int i = 1; i <= n; ++i){
		if(!components[parent[i]]){
			components[parent[i]] = true;
			if(bellman_ford(adj, n, i)){
				return true;
			}
		}
	}
	return false;
}

int main(){
	int tc;
	scanf("%d", &tc);
	vector<tuple<int, int, int>> adj;
	vector<int> parent;
	for(int a0 = 0; a0 < tc; ++a0){
		int n, m, w;
		scanf("%d %d %d", &n, &m, &w);
		adj.clear();
		parent.clear();
		parent.resize(n + 1);
		for(int i = 1; i <= n; ++i){
			parent[i] = i;
		}
		for(int i = 0; i < m; ++i){
			int s, e, t;
			scanf("%d %d %d", &s, &e, &t);
			add_edge(adj, s, e, t);
			add_edge(adj, e, s, t);
			merge(parent, s, e);
		}
		for(int i = 0; i < w; ++i){
			int s, e, t;
			scanf("%d %d %d", &s, &e, &t);
			add_edge(adj, s, e, -t);
		}
		if(has_cycle(adj, parent, n)){
			printf("YES");
		}else{
			printf("NO");
		}
		printf("\n");
	}
	return 0;
}
