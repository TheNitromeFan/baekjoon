#include <iostream>
#include <queue>
#define MAX 1001

using namespace std;

bool mine(int s[][MAX], int n, int m, int k, int d){
	queue<int> q;
	bool visited[MAX][MAX] = {};
	int mined = 0;
	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {1, 0, -1, 0};
	for(int j = 0; j < m; ++j){
		q.push(0);
		q.push(j);
		visited[0][j] = true;
	}
	for(int i = 1; i < n; ++i){
		q.push(i);
		q.push(0);
		visited[i][0] = true;
		q.push(i);
		q.push(m - 1);
		visited[i][m - 1] = true;
	}
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		if(s[x][y] > d){
			continue;
		}
		++mined;
		if(mined == k){
			return true;
		}
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]){
				q.push(nx);
				q.push(ny);
				visited[nx][ny] = true;
			}
		}
	}
	return false;
}

int find_density(int s[][MAX], int n, int m, int k){
	int low = 1, high = 1000000;
	while(low < high){
		int mid = (low + high) / 2;
		if(mine(s, n, m, k, mid)){
			high = mid;
		}else{
			low = mid + 1;
		}
	}
	return low;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	int s[MAX][MAX];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin >> s[i][j];
		}
	}
	cout << find_density(s, n, m, k);
	return 0;
}
