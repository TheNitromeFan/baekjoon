#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector<int> toposort(vector<vector<int>> &adj, vector<int> &indegree, int n){
	queue<int> q;
	for(int u = 1; u <= n; ++u){
		if(indegree[u] == 0){
			q.push(u);
		}
	}
	vector<int> ans;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		ans.push_back(u);
		for(int v : adj[u]){
			--indegree[v];
			if(indegree[v] == 0){
				q.push(v);
			}
		}
	}
	if(ans.size() != n){
		ans.clear();
		ans.push_back(0);
	}
	return ans;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	vector<vector<int>> adj(n + 1);
	vector<int> indegree(n + 1, 0);
	for(int a0 = 0; a0 < m; ++a0){
		int entries;
		scanf("%d", &entries);
		int prev, cur;
		scanf("%d", &prev);
		for(int a1 = 1; a1 < entries; ++a1){
			scanf("%d", &cur);
			adj[prev].push_back(cur);
			++indegree[cur];
			prev = cur;
		}
	}
	vector<int> ans = toposort(adj, indegree, n);
	for(int x : ans){
		printf("%d\n", x);
	}
	return 0;
}
