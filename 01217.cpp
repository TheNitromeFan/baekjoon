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
	while(true){
		int n, m;
		cin >> n >> m;
		if(n == 0 && m == 0){
			break;
		}
		vector<vector<int>> adj(2 * m + 1), rev(2 * m + 1);
		for(int i = 0; i < n; ++i){
			int a, b;
			cin >> a >> b;
			a *= -1;
			b *= -1;
			if(a < 0){
				a += 2 * m + 1;
			}
			if(b < 0){
				b += 2 * m + 1;
			}
			adj[2 * m + 1 - a].push_back(b);
			rev[b].push_back(2 * m + 1 - a);
			adj[2 * m + 1 - b].push_back(a);
			rev[a].push_back(2 * m + 1 - b);
		}
		vector<bool> visited(2 * m + 1);
		vector<int> post_order;
		for(int a = 1; a <= 2 * m; ++a){
			traverse(post_order, adj, visited, a);
		}
		reverse(post_order.begin(), post_order.end());
		vector<int> assigned(2 * m + 1, -1);
		int comp = 0;
		for(int b : post_order){
			if(assigned[b] == -1){
				++comp;
				assign(rev, assigned, b, comp);
			}
		}
		int alive = 1;
		for(int a = 1; a <= m; ++a){
			if(assigned[a] == assigned[2 * m + 1 - a]){
				alive = 0;
				break;
			}
		}
		cout << alive << '\n';
	}
	return 0;
}
