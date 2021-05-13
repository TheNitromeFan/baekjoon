#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int>> &presses){
	queue<int> q;
	vector<bool> visited(120);
	int dx[5] = {-1, 1, -10, 10, 60};
	q.push(0);
	visited[0] = true;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(int i = 0; i < 5; ++i){
			int nx = x + dx[i];
			if(nx >= 0 && nx < 120 && !visited[nx]){
				presses[nx] = presses[x];
				++presses[nx][4 - i];
				q.push(nx);
				visited[nx] = true;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<vector<int>> presses(120);
	for(int x = 0; x < 120; ++x){
		presses[x].resize(5);
	}
	bfs(presses);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int n;
		cin >> n;
		if(n < 120){
			for(int i = 0; i < 5; ++i){
				cout << presses[n][i] << ' ';
			}
			cout << '\n';
		}else{
			int q = n / 120, r = n % 120;
			cout << presses[r][0] + 2 * q << ' ';
			for(int i = 1; i < 5; ++i){
				cout << presses[r][i] << ' ';
			}
			cout << '\n';
		}
	}
	return 0;
}
