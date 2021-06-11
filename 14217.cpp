#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define MAX 501

using namespace std;

int dp[MAX];

void bfs(vector<vector<int>> &adj_vec, bool adj_mat[][MAX]){
	queue<int> q;
	memset(dp, -1, sizeof(dp));
	q.push(1);
	dp[1] = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int v : adj_vec[u]){
			if(adj_mat[u][v] && dp[v] == -1){
				q.push(v);
				dp[v] = dp[u] + 1;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj_vec(n + 1);
	bool adj_mat[MAX][MAX] = {};
	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		adj_vec[u].push_back(v);
		adj_vec[v].push_back(u);
		adj_mat[u][v] = true;
		adj_mat[v][u] = true;
	}
	int q;
	cin >> q;
	for(int j = 0; j < q; ++j){
		int a, u, v;
		cin >> a >> u >> v;
		if(a == 1){
			adj_vec[u].push_back(v);
			adj_vec[v].push_back(u);
			adj_mat[u][v] = true;
			adj_mat[v][u] = true;
		}else{
			adj_mat[u][v] = false;
			adj_mat[v][u] = false;
		}
		bfs(adj_vec, adj_mat);
		for(int city = 1; city <= n; ++city){
			cout << dp[city] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
