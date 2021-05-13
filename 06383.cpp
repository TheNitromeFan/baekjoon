#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <unordered_set>
#include <unordered_map>

using namespace std;

void visit(vector<vector<int>> &adj, unordered_map<int, bool> &visited, int start, int fail){
	queue<int> q;
	q.push(start);
	visited[start] = true;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int v : adj[u]){
			if(v != fail && !visited[v]){
				q.push(v);
				visited[v] = true;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc = 0;
	while(true){
		int u, v;
		cin >> u;
		if(u == 0){
			break;
		}
		++tc;
		cin >> v;
		vector<vector<int>> adj(1001);
		unordered_set<int> vertex_set;
		adj[u].push_back(v);
		adj[v].push_back(u);
		vertex_set.insert(u);
		vertex_set.insert(v);
		while(true){
			cin >> u;
			if(u == 0){
				break;
			}
			cin >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
			vertex_set.insert(u);
			vertex_set.insert(v);
		}
		vector<pair<int, int>> ans;
		vector<int> vertices;
		for(int u : vertex_set){
			vertices.push_back(u);
		}
		sort(vertices.begin(), vertices.end());
		for(int u : vertices){
			unordered_map<int, bool> visited;
			int cmpnt = 0;
			for(int v : vertices){
				if(v == u){
					continue;
				}
				if(!visited[v]){
					visit(adj, visited, v, u);
					++cmpnt;
				}
			}
			if(cmpnt > 1){
				ans.push_back(make_pair(u, cmpnt));
			}
		}
		cout << "Network #" << tc << '\n';
		if(!ans.empty()){
			for(pair<int, int> p : ans){
				cout << "  SPF node " << p.first << " leaves " << p.second << " subnets\n";
			}
		}else{
			cout << "  No SPF nodes\n";
		}
		cout << endl;
	}
	return 0;
}
