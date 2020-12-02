#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

bool multiple_paths(vector<vector<int>> &adj, int n, int start){
	queue<int> q;
	vector<bool> path(n + 1);
	q.push(start);
	path[start] = true;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int v : adj[u]){
			if(path[v]){
				return true;
			}else{
				q.push(v);
				path[v] = true;
			}
		}
	}
	return false;
}

bool diamond(vector<vector<int>> &adj, int n){
	for(int i = 1; i <= n; ++i){
		if(multiple_paths(adj, n, i)){
			return true;
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 1; a0 <= t; ++a0){
		int n;
		cin >> n;
		vector<vector<int>> adj(n + 1);
		for(int i = 1; i <= n; ++i){
			int mi;
			cin >> mi;
			for(int j = 0; j < mi; ++j){
				int x;
				cin >> x;
				adj[i].push_back(x);
			}
		}
		cout << "Case #" << a0 << ": " << (diamond(adj, n) ? "Yes" : "No") << "\n";
	}
	return 0;
}
