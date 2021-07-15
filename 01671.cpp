#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

bool bipartite_match(vector<vector<int>> &adj, vector<int> &matched, vector<bool> &visited, int u){
	for(int v : adj[u]){
		if(!visited[v]){
			visited[v] = true;
			if(matched[v] == -1 || bipartite_match(adj, matched, visited, matched[v])){
				matched[v] = u;
				return true;
			}
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<tuple<int, int, int>> shark(n);
	for(int i = 0; i < n; ++i){
		int size, speed, intel;
		cin >> size >> speed >> intel;
		shark[i] = make_tuple(size, speed, intel);
	}
	vector<vector<int>> adj(2 * n);
	for(int i = 0; i < n; ++i){
		int size1 = get<0>(shark[i]), speed1 = get<1>(shark[i]), intel1 = get<2>(shark[i]);
		for(int j = 0; j < i; ++j){
			int size2 = get<0>(shark[j]), speed2 = get<1>(shark[j]), intel2 = get<2>(shark[j]);
			if(size1 >= size2 && speed1 >= speed2 && intel1 >= intel2){
				adj[i].push_back(n + j);
				adj[n + j].push_back(i);
			}else if(size1 <= size2 && speed1 <= speed2 && intel1 <= intel2){
				adj[j].push_back(n + i);
				adj[n + i].push_back(n + j);
			}
		}
	}
	vector<int> matched(2 * n, -1);
	int ans = n;
	for(int i = 0; i < n; ++i){
		for(int rep = 0; rep < 2; ++rep){
			vector<bool> visited(2 * n);
			if(bipartite_match(adj, matched, visited, i)){
				--ans;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
