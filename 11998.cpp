#include <iostream>
#include <queue>
#include <cstdlib>
#include <cstring>
#define MAX 101

using namespace std;

int milk(int x, int y, int k, int m){
	queue<int> q;
	int visited[MAX][MAX];
	memset(visited, -1, sizeof(visited));
	q.push(0);
	q.push(0);
	visited[0][0] = 0;
	int closest = 0;
	while(!q.empty()){
		int a = q.front();
		q.pop();
		int b = q.front();
		q.pop();
		// cout << a << ' ' << b << ' ' << visited[a][b] << '\n';
		if(visited[a][b] == k){
			continue;
		}
		if(a < x){
			int na = x, nb = b;
			if(visited[na][nb] == -1){
				q.push(na);
				q.push(nb);
				visited[na][nb] = visited[a][b] + 1;
				if(abs(na + nb - m) < abs(closest - m)){
					closest = na + nb;
				}
			}
		}
		if(b < y){
			int na = a, nb = y;
			if(visited[na][nb] == -1){
				q.push(na);
				q.push(nb);
				visited[na][nb] = visited[a][b] + 1;
				if(abs(na + nb - m) < abs(closest - m)){
					closest = na + nb;
				}
			}
		}
		if(a > 0){
			int na = 0, nb = b;
			if(visited[na][nb] == -1){
				q.push(na);
				q.push(nb);
				visited[na][nb] = visited[a][b] + 1;
				if(abs(na + nb - m) < abs(closest - m)){
					closest = na + nb;
				}
			}
		}
		if(b > 0){
			int na = a, nb = 0;
			if(visited[na][nb] == -1){
				q.push(na);
				q.push(nb);
				visited[na][nb] = visited[a][b] + 1;
				if(abs(na + nb - m) < abs(closest - m)){
					closest = na + nb;
				}
			}
		}
		if(a < x){
			int delta = x - a;
			int na, nb;
			if(b >= delta){
				na = x;
				nb = b - delta;
			}else{
				na = a + b;
				nb = 0;
			}
			if(visited[na][nb] == -1){
				q.push(na);
				q.push(nb);
				visited[na][nb] = visited[a][b] + 1;
				if(abs(na + nb - m) < abs(closest - m)){
					closest = na + nb;
				}
			}
		}
		if(b < y){
			int delta = y - b;
			int na, nb;
			if(a >= delta){
				na = a - delta;
				nb = y;
			}else{
				na = 0;
				nb = b + a;
			}
			if(visited[na][nb] == -1){
				q.push(na);
				q.push(nb);
				visited[na][nb] = visited[a][b] + 1;
				if(abs(na + nb - m) < abs(closest - m)){
					closest = na + nb;
				}
			}
		}
	}
	return abs(closest - m);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int x, y, k, m;
	cin >> x >> y >> k >> m;
	cout << milk(x, y, k, m);
	return 0;
}
