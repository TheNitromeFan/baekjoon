#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_clique(vector<unsigned> &comp, vector<vector<int>> &adj){
	if(comp.size() < 2){
		return false;
	}
	for(unsigned i = 0; i < comp.size(); ++i){
		for(unsigned j = 0; j < i; ++j){
			if(adj[comp[i]][comp[j]] == 1){
				return false;
			}
		}
	}
	return true;
}

void visit(vector<vector<int>> &adj, unsigned n, vector<bool> &visited, vector<unsigned> &clique, unsigned x){
	visited[x] = true;
	clique.push_back(x);
	for(unsigned i = 1; i <= n; ++i){
		if(adj[x][i] == 0 && !visited[i]){
			visit(adj, n, visited, clique, i);
		}
	}
}

bool stable(vector<vector<int>> &adj, unsigned n, vector<vector<unsigned>> &cliques){
	vector<bool> visited(n + 1);
	for(unsigned i = 1; i <= n; ++i){
		if(!visited[i]){
			vector<unsigned> clique;
			visit(adj, n, visited, clique, i);
			if(!is_clique(clique, adj)){
				return false;
			}
			sort(clique.begin(), clique.end());
			cliques.push_back(clique);
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	unsigned n;
	cin >> n;
	vector<vector<int>> adj(n + 1);
	for(unsigned i = 1; i <= n; ++i){
		adj[i].resize(n + 1);
		for(unsigned j = 1; j <= n; ++j){
			cin >> adj[i][j];
		}
	}
	vector<vector<unsigned>> cliques;
	bool ans = stable(adj, n, cliques);
	if(ans){
		cout << cliques.size();
		for(unsigned i = 0; i < cliques.size(); ++i){
			cout << '\n';
			for(unsigned x : cliques[i]){
				cout << x << ' ';
			}
		}
	}else{
		cout << 0;
	}
	return 0;
}
