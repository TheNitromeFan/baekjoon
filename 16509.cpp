#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int janggi(int sx, int sy, int fx, int fy){
	queue<int> q;
	int dist[10][9];
	memset(dist, -1, sizeof(dist));
	q.push(sx);
	q.push(sy);
	dist[sx][sy] = 0;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		if(x == fx && y == fy){
			return dist[x][y];
		}
		if(x - 3 >= 0 && y - 2 >= 0
		&& !(x - 1 == fx && y == fy) && !(x - 2 == fx && y - 1 == fy)
		&& dist[x - 3][y - 2] == -1){
			q.push(x - 3);
			q.push(y - 2);
			dist[x - 3][y - 2] = dist[x][y] + 1;
		}
		if(x - 3 >= 0 && y + 2 < 9
		&& !(x - 1 == fx && y == fy) && !(x - 2 == fx && y + 1 == fy)
		&& dist[x - 3][y + 2] == -1){
			q.push(x - 3);
			q.push(y + 2);
			dist[x - 3][y + 2] = dist[x][y] + 1;
		}
		if(x + 3 < 10 && y - 2 >= 0
		&& !(x + 1 == fx && y == fy) && !(x + 2 == fx && y - 1 == fy)
		&& dist[x + 3][y - 2] == -1){
			q.push(x + 3);
			q.push(y - 2);
			dist[x + 3][y - 2] = dist[x][y] + 1;
		}
		if(x + 3 < 10 && y + 2 < 9
		&& !(x + 1 == fx && y == fy) && !(x + 2 == fx && y + 1 == fy)
		&& dist[x + 3][y + 2] == -1){
			q.push(x + 3);
			q.push(y + 2);
			dist[x + 3][y + 2] = dist[x][y] + 1;
		}
		if(x - 2 >= 0 && y - 3 >= 0
		&& !(x == fx && y - 1 == fy) && !(x - 1 == fx && y - 2 == fy)
		&& dist[x - 2][y - 3] == -1){
			q.push(x - 2);
			q.push(y - 3);
			dist[x - 2][y - 3] = dist[x][y] + 1;
		}
		if(x - 2 >= 0 && y + 3 < 9
		&& !(x == fx && y + 1 == fy) && !(x - 1 == fx && y + 2 == fy)
		&& dist[x - 2][y + 3] == -1){
			q.push(x - 2);
			q.push(y + 3);
			dist[x - 2][y + 3] = dist[x][y] + 1;
		}
		if(x + 2 < 10 && y - 3 >= 0
		&& !(x == fx && y - 1 == fy) && !(x + 1 == fx && y - 2 == fy)
		&& dist[x + 2][y - 3] == -1){
			q.push(x + 2);
			q.push(y - 3);
			dist[x + 2][y - 3] = dist[x][y] + 1;
		}
		if(x + 2 < 10 && y + 3 < 9
		&& !(x == fx && y + 1 == fy) && !(x + 1 == fx && y + 2 == fy)
		&& dist[x + 2][y + 3] == -1){
			q.push(x + 2);
			q.push(y + 3);
			dist[x + 2][y + 3] = dist[x][y] + 1;
		}
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;
	cout << janggi(r1, c1, r2, c2);
	return 0;
}
