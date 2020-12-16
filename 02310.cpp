#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool navigate(vector<int> &rooms, vector<vector<int>> &adj, int n, vector<bool> &visited, int u, int gold){
	if(gold + rooms[u] < 0){
		return false;
	}
	int new_gold = gold;
	if(rooms[u] > 0){
		new_gold = max(gold, rooms[u]);
	}else if(rooms[u] < 0){
		new_gold += rooms[u];
	}
	if(u == n){
		return true;
	}
	visited[u] = true;
	bool ret = false;
	for(int v : adj[u]){
		if(!visited[v] && navigate(rooms, adj, n, visited, v, new_gold)){
			ret = true;
			break;
		}
	}
	visited[u] = false;
	return ret;
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
		vector<int> rooms(n + 1);
		vector<vector<int>> adj(n + 1);
		for(int i = 1; i <= n; ++i){
			char creature;
			int val;
			cin >> creature >> val;
			if(creature == 'T'){
				rooms[i] = -val;
			}else{
				rooms[i] = val;
			}
			int x;
			while(true){
				cin >> x;
				if(x == 0){
					break;
				}
				adj[i].push_back(x);
			}
		}
		vector<bool> visited(n + 1);
		cout << (navigate(rooms, adj, n, visited, 1, 0) ? "Yes" : "No") << "\n";
	}
	return 0;
}
