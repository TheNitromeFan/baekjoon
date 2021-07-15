#include <cstdio>
#include <vector>
#include <utility>
#define MAX 302

using namespace std;

bool match(int a[MAX], int b[MAX], int n){
	for(int j = 1; j <= n; ++j){
		if(a[j] != b[j]){
			return false;
		}
	}
	return true;
}

int find_match(int adj[][MAX], int n, int i){
	for(int j = 1; j < i; ++j){
		if(match(adj[i], adj[j], n)){
			return j;
		}
	}
	return -1;
}

bool contains(int a[MAX], int b[MAX], int n){
	for(int j = 1; j <= n; ++j){
		if(!a[j] && b[j]){
			return false;
		}
	}
	return true;
}

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		int n;
		scanf("%d", &n);
		int adj[MAX][MAX];
		for(int i = 1; i <= n; ++i){
			char c[MAX];
			scanf("%s", c);
			for(int j = 1; j <= n; ++j){
				adj[i][j] = c[j - 1] - '0';
			}
		}
		int scc_count = 0;
		vector<int> scc(n + 1);
		for(int i = 1; i <= n; ++i){
			int j = find_match(adj, n, i);
			if(j == -1){
				++scc_count;
				scc[i] = scc_count;
			}else{
				scc[i] = scc[j];
			}
		}
		vector<vector<int>> scc_vertices(scc_count + 1);
		for(int i = 1; i <= n; ++i){
			scc_vertices[scc[i]].push_back(i);
		}
		vector<pair<int, int>> ans;
		for(int s = 1; s <= scc_count; ++s){
			if(scc_vertices[s].size() <= 1){
				continue;
			}
			unsigned n = scc_vertices[s].size();
			scc_vertices[s].push_back(scc_vertices[s][0]);
			for(unsigned idx = 0; idx < n; ++idx){
				ans.push_back(make_pair(scc_vertices[s][idx], scc_vertices[s][idx + 1]));
			}
			scc_vertices[s].pop_back();
		}
		int adj1[MAX][MAX] = {};
		for(int s = 1; s <= scc_count; ++s){
			for(int t = 1; t <= scc_count; ++t){
				if(s == t){
					continue;
				}
				int u = scc_vertices[s][0];
				int v = scc_vertices[t][0];
				if(contains(adj[u], adj[v], n)){
					adj1[u][v] = 1;
				}
			}
		}
		for(int k = 1; k <= n; ++k){
			for(int i = 1; i <= n; ++i){
				for(int j = 1; j <= n; ++j){
					if(adj1[i][j] && adj1[i][k] && adj1[k][j]){
						adj1[i][j] = 0;
					}
				}
			}
		}
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= n; ++j){
				if(adj1[i][j]){
					ans.push_back(make_pair(i, j));
				}
			}
		}
		printf("%llu\n", ans.size());
		for(pair<int, int> p : ans){
			printf("%d %d\n", p.first, p.second);
		}
		printf("\n");
	}
	return 0;
}
