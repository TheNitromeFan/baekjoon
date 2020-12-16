#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int time(vector<vector<int>> &teleports, int n, int start, int end){
	queue<int> q;
	vector<int> dist(n + 1, -1);
	q.push(start);
	dist[start] = 0;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		if(x == end){
			return dist[x];
		}
		if(x < n && dist[x + 1] == -1){
			q.push(x + 1);
			dist[x + 1] = dist[x] + 1;
		}
		if(x > 1 && dist[x - 1] == -1){
			q.push(x - 1);
			dist[x - 1] = dist[x] + 1;
		}
		for(int y : teleports[x]){
			if(dist[y] == -1){
				q.push(y);
				dist[y] = dist[x] + 1;
			}
		}
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	int s, e;
	cin >> s >> e;
	vector<vector<int>> teleports(n + 1);
	for(int i = 0; i < m; ++i){
		int x, y;
		cin >> x >> y;
		teleports[x].push_back(y);
		teleports[y].push_back(x);
	}
	cout << time(teleports, n, s, e);
	return 0;
}
