#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void traverse(vector<int> &post_order, vector<vector<int>> &adj, vector<bool> &visited, int u){
	if(visited[u]){
		return;
	}
	visited[u] = true;
	for(int v : adj[u]){
		traverse(post_order, adj, visited, v);
	}
	post_order.push_back(u);
}

void assign_scc(vector<int> &assigned, vector<vector<int>> &rev, int v, int scc){
	if(assigned[v] != -1){
		return;
	}
	assigned[v] = scc;
	for(int u : rev[v]){
		assign_scc(assigned, rev, u, scc);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		int n;
		cin >> n;
		if(n == 0){
			break;
		}
		vector<bool> is_option(26);
		vector<vector<int>> adj(26), rev(26);
		for(int i = 0; i < n; ++i){
			vector<char> options(5);
			for(int j = 0; j < 5; ++j){
				cin >> options[j];
				is_option[options[j] - 'A'] = true;
			}
			char select;
			cin >> select;
			int u = select - 'A';
			for(int j = 0; j < 5; ++j){
				int v = options[j] - 'A';
				adj[u].push_back(v);
				rev[v].push_back(u);
			}
		}
		vector<bool> visited(26);
		vector<int> post_order;
		for(int u = 0; u < 26; ++u){
			traverse(post_order, adj, visited, u);
		}
		reverse(post_order.begin(), post_order.end());
		vector<int> scc(26, -1);
		int scc_count = 0;
		for(int v : post_order){
			if(scc[v] == -1){
				assign_scc(scc, rev, v, scc_count);
				++scc_count;
			}
		}
		fill(visited.begin(), visited.end(), false);
		for(int u = 0; u < 26; ++u){
			if(!is_option[u] || visited[u]){
				continue;
			}
			int s = scc[u];
			for(int v = 0; v < 26; ++v){
				if(is_option[v] && scc[v] == s){
					visited[v] = true;
					cout << (char)(v + 'A') << ' ';
				}
			}
			cout << '\n';
		}
		cout << '\n';
	}
	return 0;
}
