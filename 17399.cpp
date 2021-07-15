#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 100005

using namespace std;

int depth[MAXN];
int dp[MAXN][20];

void dfs(vector<vector<int>> &adj, int cur, int prev){
	depth[cur] = depth[prev] + 1;
	dp[cur][0] = prev;
	for(int i = 1; i <= 19; ++i){
		int p = dp[cur][i - 1];
		dp[cur][i] = dp[p][i - 1];
	}
	for(int next : adj[cur]){
		if(next != prev){
			dfs(adj, next, cur);
		}
	}
}

int lca(int u, int v){
	if(depth[u] != depth[v]){
		if(depth[u] > depth[v]){
			swap(u, v);
		}
		for(int i = 19; i >= 0; --i){
			int p = dp[v][i];
			if(depth[u] <= depth[p]){
				v = p;
			}
		}
	}
	int ret = u;
	if(u != v){
		for(int i = 19; i >= 0; --i){
			if(dp[u][i] != dp[v][i]){
				u = dp[u][i];
				v = dp[v][i];
			}
			ret = dp[u][i];
		}
	}
	return ret;
}

int dist(int a, int b){
	if(a == -1 || b == -1){
		return -1;
	}
	int c = lca(a, b);
	return depth[a] + depth[b] - 2 * depth[c] + 1;
}

int center(int a, int b){
	if(a > b){
		swap(a, b);
	}
	int c = lca(a, b);
	int total_dist = depth[a] + depth[b] - 2 * depth[c] + 1;
	if(total_dist % 2 == 0){
 		return -1;
	}
	int k = (total_dist + 1) / 2;
	int kth = 0;
	if(depth[a] - depth[c] + 1 >= k){
		--k;
		kth = a;
		for(int i = 19; i >= 0; --i){
			if((1 << i) <= k){
				k -= 1 << i;
				kth = dp[kth][i];
			}
		}
	}else{
		kth = b;
		k = depth[a] + depth[b] - 2 * depth[c] - k + 1;
		for(int i = 19; i >= 0; --i){
			if((1 << i) <= k){
				k -= 1 << i;
				kth = dp[kth][i];
			}
		}
	}
	return kth;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<vector<int>> adj(n + 1);
	for(int a0 = 0; a0 < n - 1; ++a0){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	depth[0] = -1;
	dfs(adj, 1, 0);
	int q;
	cin >> q;
	for(int a1 = 0; a1 < q; ++a1){
		int a, b, c;
		cin >> a >> b >> c;
		if(a == b && a == c){
			cout << a << '\n';
			continue;
		}else if(a == b || b == c || c == a){
			int small = min(min(a, b), c);
			int big = max(max(a, b), c);
			cout << center(small, big) << '\n';
			continue;
		}
		int ab_center = center(a, b);
		int bc_center = center(b, c);
		int ca_center = center(c, a);
		if(dist(a, ab_center) == dist(c, ab_center)){
			cout << ab_center << '\n';
		}else if(dist(b, bc_center) == dist(a, bc_center)){
			cout << bc_center << '\n';
		}else if(dist(c, ca_center) == dist(b, ca_center)){
			cout << ca_center << '\n';
		}else{
			cout << -1 << '\n';
		}
	}
	return 0;
}
