#include <iostream>
#include <vector>
#include <string>
#include <queue>
#define MAX 1000000

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	unsigned a, b;
	cin >> a >> b;
	string s;
	cin >> s;
	vector<vector<int>> adj(MAX);
	vector<int> prev(MAX);
	int cur = 0, cnt = 1;
	int src = -1, dest = -1;
	for(unsigned idx = 0; idx < s.length(); ++idx){
		if(idx == a){
			src = cur;
		}
		if(idx == b){
			dest = cur;
		}
		char c = s[idx];
		if(c == 'U'){
			adj[cur].push_back(cnt);
			adj[cnt].push_back(cur);
			prev[cnt] = cur;
			cur = cnt;
			++cnt;
		}else{
			cur = prev[cur];
		}
 	}
	queue<int> q;
	vector<int> dist(MAX, -1);
	q.push(src);
	dist[src] = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		if(u == dest){
			break;
		}
		for(int v : adj[u]){
			if(dist[v] == -1){
				q.push(v);
				dist[v] = dist[u] + 1;
			}
		}
	}
	cout << dist[dest] << '\n';
	return 0;
}
