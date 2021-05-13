#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<vector<int>> adj(13);
	for(int i = 0; i < 12; ++i){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> degree3;
	for(int v = 1; v <= 12; ++v){
		if(adj[v].size() == 3){
			degree3.push_back(v);
		}
	}
	sort(degree3.begin(), degree3.end());
	int v1 = 0, v2 = 0, v3 = 0, v4 = 0;
	do{
		v1 = degree3[0];
		v2 = degree3[1];
		v3 = degree3[2];
		v4 = degree3[3];
		if(find(adj[v1].begin(), adj[v1].end(), v2) != adj[v1].end()
		&& find(adj[v2].begin(), adj[v2].end(), v3) != adj[v2].end()
		&& find(adj[v3].begin(), adj[v3].end(), v4) != adj[v3].end()){
			break;
		}
	}while(next_permutation(degree3.begin(), degree3.end()));
	if(adj[adj[v1][0]].size() == 1 || adj[adj[v1][1]].size() == 1  || adj[adj[v1][2]].size() == 1){
		cout << v1;
	}else{
		cout << v4;
	}
	return 0;
}
