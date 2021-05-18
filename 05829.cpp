#include <iostream>
#include <vector>

using namespace std;

void traverse(vector<vector<int>> &adj, int &pos, vector<int> &instr){
	for(int x : instr){
		pos = adj[pos][x];
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> adj(n + 1);
	for(int i = 1; i <= n; ++i){
		int left, right;
		cin >> left >> right;
		adj[i].push_back(left);
		adj[i].push_back(right);
	}
	vector<int> instr(m);
	for(int j = 0; j < m; ++j){
		char c;
		cin >> c;
		if(c == 'R'){
			instr[j] = 1;
		}
	}
	vector<int> memo(n + 1, -1);
	int pos = 1;
	for(int rep = 0; rep < k; ++rep){
		if(memo[pos] != -1){
			int period = rep - memo[pos];
			int remaining = k - rep;
			for(int rep1 = 0; rep1 < remaining % period; ++rep1){
				traverse(adj, pos, instr);
			}
			cout << pos << '\n';
			return 0;
		}
		memo[pos] = rep;
		traverse(adj, pos, instr);
	}
	cout << pos << '\n';
	return 0;
}
