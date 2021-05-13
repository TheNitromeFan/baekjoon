#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

void bfs(pair<int, int> prev[][8], int x1, int y1, int x2, int y2){
	queue<int> q;
	bool visited[8][8] = {};
	q.push(x1);
	q.push(y1);
	visited[x1][y1] = true;
	int dx[4] = {-1, 1, 1, -1};
	int dy[4] = {-1, -1, 1, 1};
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		if(x == x2 && y == y2){
			return;
		}
		// cout << x << ' ' << y << '\n';
		for(int i = 0; i < 4; ++i){
			int nx = x, ny = y;
			while(true){
				nx += dx[i];
				ny += dy[i];
				if(!(nx >= 0 && nx < 8 && ny >= 0 && ny < 8)){
					break;
				}
				if(!visited[nx][ny]){
					q.push(nx);
					q.push(ny);
					visited[nx][ny] = true;
					prev[nx][ny] = make_pair(x, y);
				}
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		char f1, f2;
		int r1, r2;
		cin >> f1 >> r1 >> f2 >> r2;
		int x1 = f1 - 'A', x2 = f2 - 'A', y1 = r1 - 1, y2 = r2 - 1;
		if((x1 + y1) % 2 != (x2 + y2) % 2){
			cout << "Impossible\n";
			continue;
		}
		pair<int, int> prev[8][8];
		bfs(prev, x1, y1, x2, y2);
		vector<pair<int, int>> v = {make_pair(x2, y2)};
		while(!(x2 == x1 && y2 == y1)){
			pair<int, int> p = prev[x2][y2];
			v.push_back(p);
			x2 = p.first;
			y2 = p.second;
		}
		reverse(v.begin(), v.end());
		cout << v.size() - 1;
		for(pair<int, int> p : v){
			cout << ' ' << (char)(p.first + 'A') << ' ' << p.second + 1;
		}
		cout << '\n';
	}
	return 0;
}
