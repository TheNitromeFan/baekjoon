#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> times(n + 1);
	vector<vector<int>> adj(n + 1);
	for(int u = 1; u <= n; ++u){
		cin >> times[u];
		int jobs;
		cin >> jobs;
		for(int j = 0; j < jobs; ++j){
			int v;
			cin >> v;
			adj[v].push_back(u);
		}
	}
	vector<int> cumulative(n + 1);
	int ans = 0;
	for(int u = 1; u <= n; ++u){
		cumulative[u] += times[u];
		for(int v : adj[u]){
			cumulative[v] = max(cumulative[v], cumulative[u]);
		}
		ans = max(ans, cumulative[u]);
		// cout << u << " : " << cumulative[u] << "\n";
	}
	cout << ans;
	return 0;
}
