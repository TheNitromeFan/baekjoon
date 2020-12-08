#include <iostream>
#include <vector>

using namespace std;

unsigned connect(bool adj[][51], unsigned n){
	vector<pair<unsigned, unsigned>> pairs;
	for(unsigned i = 1; i <= n; ++i){
		for(unsigned j = 1; j < i; ++j){
			if(!adj[i][j]){
				for(unsigned k = 1; k <= n; ++k){
					if(adj[i][k] && adj[k][j]){
						pairs.push_back(make_pair(i, j));
						break;
					}
				}
			}
		}
	}
	for(pair<unsigned, unsigned> p : pairs){
		unsigned i = p.first, j = p.second;
		adj[i][j] = true;
		adj[j][i] = true;
	}
	return pairs.size();
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	unsigned n, m;
	cin >> n >> m;
	bool adj[51][51] = {};
	for(unsigned v = 1; v <= n; ++v){
		adj[v][v] = true;
	}
	for(unsigned i = 0; i < m; ++i){
		unsigned a, b;
		cin >> a >> b;
		adj[a][b] = true;
		adj[b][a] = true;
	}
	vector<unsigned> ans;
	while(m < n * (n - 1) / 2){
		unsigned x = connect(adj, n);
		ans.push_back(x);
		m += x;
	}
	cout << ans.size();
	for(unsigned x : ans){
		cout << '\n' << x;
	}
	return 0;
}
