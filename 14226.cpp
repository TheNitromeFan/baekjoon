#include <iostream>
#include <queue>
#include <cstring>
#define MAX 2050

using namespace std;

int emoticon(int n){
	queue<int> q;
	int dist[MAX][MAX];
	memset(dist, -1, sizeof(dist));
	q.push(1);
	q.push(0);
	dist[1][0] = 0;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		if(x == n){
			return dist[x][y];
		}
		if(dist[x][x] == -1){
			q.push(x);
			q.push(x);
			dist[x][x] = dist[x][y] + 1;
		}
		if(x + y < MAX && dist[x + y][y] == -1){
			q.push(x + y);
			q.push(y);
			dist[x + y][y] = dist[x][y] + 1;
		}
		if(x > 0 && dist[x - 1][y] == -1){
			q.push(x - 1);
			q.push(y);
			dist[x - 1][y] = dist[x][y] + 1;
		}
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	cout << emoticon(n);
	return 0;
}
