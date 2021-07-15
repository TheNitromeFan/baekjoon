#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

int bfs(int start){
	queue<int> q;
	unordered_map<int, int> dist;
	int dx[4] = {1, -1, 0, 0};
	int dy[4] = {0, 0, 1, -1};
	q.push(start);
	dist[start] = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		if(u == 123456789){
			return dist[u];
		}
		string s = to_string(u);
		int idx = s.find('9');
		int x = idx / 3;
		int y = idx % 3;
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(!(nx >= 0 && nx < 3 && ny >= 0 && ny < 3)){
				continue;
			}
			int nidx = 3 * nx + ny;
			string t = s;
			swap(t[idx], t[nidx]);
			int v = stoi(t);
			if(dist.find(v) == dist.end()){
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
	int state = 0;
	for(int i = 0; i < 9; ++i){
		int x;
		cin >> x;
		if(x == 0){
			x = 9;
		}
		state = state * 10 + x;
	}
	cout << bfs(state) << '\n';
	return 0;
}
