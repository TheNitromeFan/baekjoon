#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int jumps(vector<int> &vec, int n, int a, int b){
	queue<int> q;
	vector<int> dist(n + 1, -1);
	q.push(a);
	dist[a] = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		if(u == b){
			return dist[u];
		}
		for(int v = u; v >= 1; v -= vec[u]){
			if(dist[v] == -1){
				q.push(v);
				dist[v] = dist[u] + 1;
			}
		}
		for(int v = u; v <= n; v += vec[u]){
			if(dist[v] == -1){
				q.push(v);
				dist[v] = dist[u] + 1;
			}
		}
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n + 1);
	for(int i = 1; i <= n; ++i){
		cin >> v[i];
	}
	int a, b;
	cin >> a >> b;
	cout << jumps(v, n, a, b);
	return 0;
}
