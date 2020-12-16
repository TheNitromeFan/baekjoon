#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#define MAX 201

using namespace std;

void spread(int dish[][MAX], int time[][MAX], int n, int s, queue<int> &q){
	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {1, 0, -1, 0};
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		if(time[x][y] == s){
			continue;
		}
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 0 && nx < n && ny >= 0 && ny < n && dish[nx][ny] == 0){
				q.push(nx);
				q.push(ny);
				dish[nx][ny] = dish[x][y];
				time[nx][ny] = time[nx][ny] + 1;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	int dish[MAX][MAX];
	vector<vector<pair<int, int>>> viruses(k + 1);
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cin >> dish[i][j];
			if(dish[i][j] != 0){
				viruses[dish[i][j]].push_back(make_pair(i, j));
			}
		}
	}
	int s, x, y;
	cin >> s >> x >> y;
	queue<int> q;
	for(int virus = 1; virus <= k; ++virus){
		for(pair<int, int> p : viruses[virus]){
			q.push(p.first);
			q.push(p.second);
		}
	}
	int time[MAX][MAX] = {};
	spread(dish, time, n, s, q);
	/*
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cout << dish[i][j] << ' ';
		}
		cout << '\n';
	}
	*/
	cout << dish[x - 1][y - 1];
	return 0;
}
