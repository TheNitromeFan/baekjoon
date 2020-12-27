#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int number(string &vertex){
	int ret = 0;
	for(unsigned i = 1; i < vertex.length(); ++i){
		ret *= 10;
		ret += vertex[i] - '0';
	}
	return ret;
}

int neighborhood(vector<vector<int>> &adj, int n, int src){
	queue<int> q;
	vector<int> dist(n + 1, -1);
	q.push(src);
	dist[src] = 0;
	int cnt = -1;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		++cnt;
		if(dist[u] == 2){
			continue;
		}
		for(int v : adj[u]){
			if(dist[v] == -1){
				q.push(v);
				dist[v] = dist[u] + 1;
			}
		}
	}
	return cnt;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> adj(n + 1);
		for(int i = 0; i < m; ++i){
			string u, v;
			cin >> u >> v;
			int src = number(u), dest = number(v);
			adj[src].push_back(dest);
			adj[dest].push_back(src);
		}
		string u;
		cin >> u;
		int src = number(u);
		cout << "The number of supervillains in 2-hop neighborhood of v" << src << " is "
		<< neighborhood(adj, n, src) << "\n";
	}
	return 0;
}
