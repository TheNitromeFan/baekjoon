#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, p;
	cin >> n >> m >> p;
	vector<int> adj(m + 1, -1);
	for(int i = 0; i < n; ++i){
		int a, b;
		cin >> a >> b;
		if(adj[b] == -1){
			adj[b] = a;
		}
	}
	vector<int> visited(m + 1);
	visited[p] = true;
	int changes = 0;
	while(adj[p] != -1){
		int q = adj[p];
		if(visited[q]){
			cout << -1;
			return 0;
		}
		p = q;
		visited[p] = true;
		++changes;
	}
	cout << changes;
	return 0;
}
