#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<vector<int>> adj(n + 1);
	for(int i = 0; i < n - 1; ++i){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int leaves = 0;
	for(int u = 1; u <= n; ++u){
		if(adj[u].size() == 1){
			++leaves;
		}
	}
	cout << max(0, leaves - 2);
	return 0;
}
