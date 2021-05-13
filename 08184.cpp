#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool has_singleton(vector<vector<int>> &adj, int n){
	for(int u = 1; u <= n; ++u){
		if(adj[u].empty()){
			return true;
		}
	}
	return false;
}

void assign(vector<vector<int>> &adj, vector<int> &assigned, int start){
	queue<int> q;
	q.push(start);
	assigned[start] = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int v : adj[u]){
			if(assigned[v] != -1){
				continue;
			}
			q.push(v);
			assigned[v] = 1 - assigned[u];
		}
	}
}

void guild_offices(vector<vector<int>> &adj, int n){
	if(has_singleton(adj, n)){
		cout << "NIE\n";
		return;
	}
	cout << "TAK\n";
	vector<int> assigned(n + 1, -1);
	for(int u = 1; u <= n; ++u){
		if(assigned[u] == -1){
			assign(adj, assigned, u);
		}
		if(assigned[u]){
			cout << "K\n";
		}else{
			cout << "S\n";
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	guild_offices(adj, n);
	return 0;
}
