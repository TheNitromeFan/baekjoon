#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void traverse(vector<vector<int>> &adj, vector<bool> &visited, vector<int> &left, vector<int> &right, int v, int &cnt){
	visited[v] = true;
	left[v] = cnt;
	++cnt;
	for(int x : adj[v]){
		if(!visited[x]){
			traverse(adj, visited, left, right, x, cnt);
		}
	}
	right[v] = cnt;
	++cnt;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<vector<int>> adj(n + 1);
	for(int i = 1; i <= n; ++i){
		int v;
		cin >> v;
		while(true){
			int x;
			cin >> x;
			if(x == -1){
				break;
			}
			adj[v].push_back(x);
		}
		sort(adj[v].begin(), adj[v].end());
	}
	int s;
	cin >> s;
	vector<int> left(n + 1), right(n + 1);
	vector<bool> visited(n + 1);
	int cnt = 1;
	traverse(adj, visited, left, right, s, cnt);
	for(int v = 1; v <= n; ++v){
		cout << v << ' ' << left[v] << ' ' << right[v] << '\n';
	}
	return 0;
}
