#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> adj(n + 1);
	vector<int> indegree(n + 1);
	for(int a0 = 0; a0 < m; ++a0){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		++indegree[v];
	}
	vector<int> built(n + 1);
	for(int a1 = 0; a1 < k; ++a1){
		int op, a;
		cin >> op >> a;
		if(op == 1){
			if(indegree[a] == 0){
				if(built[a] == 0){
					for(int b : adj[a]){
						--indegree[b];
					}
				}
				++built[a];
			}else{
				cout << "Lier!";
				return 0;
			}
		}else{
			if(built[a] > 0){
				--built[a];
				if(built[a] == 0){
					for(int b : adj[a]){
						++indegree[b];
					}
				}
			}else{
				cout << "Lier!";
				return 0;
			}
		}
	}
	cout << "King-God-Emperor";
	return 0;
}
