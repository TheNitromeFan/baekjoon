#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void traverse(vector<int> &post_order, vector<vector<int>> &adj, vector<bool> &visited, int a){
	if(visited[a]){
		return;
	}
	visited[a] = true;
	for(int b : adj[a]){
		traverse(post_order, adj, visited, b);
	}
	post_order.push_back(a);
}

void assign(vector<vector<int>> &rev, vector<int> &assigned, int b, int root){
	if(assigned[b] != -1){
		return;
	}
	assigned[b] = root;
	for(int a : rev[b]){
		assign(rev, assigned, a, root);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int n, m, k;
		cin >> n >> m >> k;
		vector<vector<int>> adj(2 * (n + m) + 1), rev(2 * (n + m) + 1);
		for(int i = 0; i < k; ++i){
			int sx, sy, fx, fy;
			cin >> sx >> sy >> fx >> fy;
			sy += n;
			fy += n;
			if(sx == fx && sy == fy){
				continue;
			}else if(sy == fy){
				if(sx < fx){
					adj[2 * (n + m) + 1 - sy].push_back(sy);
					rev[sy].push_back(2 * (n + m) + 1 - sy);
				}else{
					adj[sy].push_back(2 * (n + m) + 1 - sy);
					rev[2 * (n + m) + 1 - sy].push_back(sy);
				}
			}else if(sx == fx){
				if(sy < fy){
					adj[2 * (n + m) + 1 - sx].push_back(sx);
					rev[sx].push_back(2 * (n + m) + 1 - sx);
				}else{
					adj[sx].push_back(2 * (n + m) + 1 - sx);
					rev[2 * (n + m) + 1 - sx].push_back(sx);
				}
			}else{
				if(sx < fx && sy < fy){
					adj[2 * (n + m) + 1 - sx].push_back(sy);
					rev[sy].push_back(2 * (n + m) + 1 - sx);
					adj[2 * (n + m) + 1 - sy].push_back(sx);
					rev[sx].push_back(2 * (n + m) + 1 - sy);
					adj[2 * (n + m) + 1 - sx].push_back(fx);
					rev[fx].push_back(2 * (n + m) + 1 - sx);
					adj[2 * (n + m) + 1 - fx].push_back(sx);
					rev[sx].push_back(2 * (n + m) + 1 - fx);
					adj[2 * (n + m) + 1 - fy].push_back(sy);
					rev[sy].push_back(2 * (n + m) + 1 - fy);
					adj[2 * (n + m) + 1 - sy].push_back(fy);
					rev[fy].push_back(2 * (n + m) + 1 - sy);
					adj[2 * (n + m) + 1 - fy].push_back(fx);
					rev[fx].push_back(2 * (n + m) + 1 - fy);
					adj[2 * (n + m) + 1 - fx].push_back(fy);
					rev[fy].push_back(2 * (n + m) + 1 - fx);
				}else if(sx > fx && sy < fy){
					adj[2 * (n + m) + 1 - sx].push_back(2 * (n + m) + 1 - sy);
					rev[2 * (n + m) + 1 - sy].push_back(2 * (n + m) + 1 - sx);
					adj[sy].push_back(sx);
					rev[sx].push_back(sy);
					adj[2 * (n + m) + 1 - sx].push_back(fx);
					rev[fx].push_back(2 * (n + m) + 1 - sx);
					adj[2 * (n + m) + 1 - fx].push_back(sx);
					rev[sx].push_back(2 * (n + m) + 1 - fx);
					adj[fy].push_back(2 * (n + m) + 1 - sy);
					rev[2 * (n + m) + 1 - sy].push_back(fy);
					adj[sy].push_back(2 * (n + m) + 1 - fy);
					rev[2 * (n + m) + 1 - fy].push_back(sy);
					adj[fy].push_back(fx);
					rev[fx].push_back(fy);
					adj[2 * (n + m) + 1 - fx].push_back(2 * (n + m) + 1 - fy);
					rev[2 * (n + m) + 1 - fy].push_back(2 * (n + m) + 1 - fx);
				}else if(sx < fx && sy > fy){
					adj[sx].push_back(sy);
					rev[sy].push_back(sx);
					adj[2 * (n + m) + 1 - sy].push_back(2 * (n + m) + 1 - sx);
					rev[2 * (n + m) + 1 - sx].push_back(2 * (n + m) + 1 - sy);
					adj[sx].push_back(2 * (n + m) + 1 - fx);
					rev[2 * (n + m) + 1 - fx].push_back(sx);
					adj[fx].push_back(2 * (n + m) + 1 - sx);
					rev[2 * (n + m) + 1 - sx].push_back(fx);
					adj[2 * (n + m) + 1 - fy].push_back(sy);
					rev[sy].push_back(2 * (n + m) + 1 - fy);
					adj[2 * (n + m) + 1 - sy].push_back(fy);
					rev[fy].push_back(2 * (n + m) + 1 - sy);
					adj[2 * (n + m) + 1 - fy].push_back(2 * (n + m) + 1 - fx);
					rev[2 * (n + m) + 1 - fx].push_back(2 * (n + m) + 1 - fy);
					adj[fx].push_back(fy);
					rev[fy].push_back(fx);
				}else{
					adj[sx].push_back(2 * (n + m) + 1 - sy);
					rev[2 * (n + m) + 1 - sy].push_back(sx);
					adj[sy].push_back(2 * (n + m) + 1 - sx);
					rev[2 * (n + m) + 1 - sx].push_back(sy);
					adj[sx].push_back(2 * (n + m) + 1 - fx);
					rev[2 * (n + m) + 1 - fx].push_back(sx);
					adj[fx].push_back(2 * (n + m) + 1 - sx);
					rev[2 * (n + m) + 1 - sx].push_back(fx);
					adj[fy].push_back(2 * (n + m) + 1 - sy);
					rev[2 * (n + m) + 1 - sy].push_back(fy);
					adj[sy].push_back(2 * (n + m) + 1 - fy);
					rev[2 * (n + m) + 1 - fy].push_back(sy);
					adj[fy].push_back(2 * (n + m) + 1 - fx);
					rev[2 * (n + m) + 1 - fx].push_back(fy);
					adj[fx].push_back(2 * (n + m) + 1 - fy);
					rev[2 * (n + m) + 1 - fy].push_back(fx);
				}
			}
		}
		vector<bool> visited(2 * (n + m) + 1);
		vector<int> post_order;
		for(int a = 1; a <= 2 * (n + m); ++a){
			traverse(post_order, adj, visited, a);
		}
		reverse(post_order.begin(), post_order.end());
		vector<int> assigned(2 * (n + m) + 1, -1);
		int comp = 0;
		for(int b : post_order){
			if(assigned[b] == -1){
				++comp;
				assign(rev, assigned, b, comp);
			}
		}
		bool sat = true;
		for(int a = 1; a <= n + m; ++a){
			if(assigned[a] == assigned[2 * (n + m) + 1 - a]){
				sat = false;
				break;
			}
		}
		cout << (sat ? "Yes\n" : "No\n");
	}
	return 0;
}
