#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

bool visited[10001], assigned[10001];
stack<int> s;
vector<vector<int>> adj, rev_adj, scc;

void visit(int u){
	if(!visited[u]){
		visited[u] = true;
		for(int v : adj[u]){
			visit(v);
		}
		s.push(u);
	}
}

void assign(int u){
	if(!assigned[u]){
		assigned[u] = true;
		scc[scc.size()-1].push_back(u);
		for(int v : rev_adj[u]){
			assign(v);
		}
	}
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	adj.resize(n+1);
	rev_adj.resize(n+1);
	for(int i = 0; i < m; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		rev_adj[v].push_back(u);
	}
	for(int u = 1; u <= n; ++u){
		visit(u);
	}
	int components = 0;
	while(!s.empty()){
		int u = s.top();
		s.pop();
		if(!assigned[u]){
			vector<int> tmp;
			scc.push_back(tmp);
		}
		assign(u);
	}
	for(int i = 0; i < scc.size(); ++i){
		sort(scc[i].begin(), scc[i].end());
	}
	sort(scc.begin(), scc.end());
	printf("%d\n", scc.size());
	for(int i = 0; i < scc.size(); ++i){
		for(int j = 0; j < scc[i].size(); ++j){
			printf("%d ", scc[i][j]);
		}
		printf("-1\n");
	}
	return 0;
}
