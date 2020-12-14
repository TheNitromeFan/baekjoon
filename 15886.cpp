#include <iostream>
#include <string>
#include <vector>

using namespace std;

void visit(vector<vector<int>> &adj, vector<bool> &visited, int x){
	visited[x] = true;
	for(int y : adj[x]){
		if(!visited[y]){
			visit(adj, visited, y);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<bool> visited(n);
	string s;
	cin >> s;
	vector<vector<int>> adj(n);
	for(int i = 0; i < n; ++i){
		if(s[i] == 'E'){
			adj[i].push_back(i + 1);
			adj[i + 1].push_back(i);
		}else if(s[i] == 'W'){
			adj[i].push_back(i - 1);
			adj[i - 1].push_back(i);
		}
	}
	int cnt = 0;
	for(int i = 0; i < n; ++i){
		if(!visited[i]){
			++cnt;
			visit(adj, visited, i);
		}
	}
	cout << cnt;
	return 0;
}
