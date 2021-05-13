#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 501

using namespace std;

void order(int &a, int &b, int &c){
	if(a <= c && c <= b){
		swap(b, c);
	}else if(b <= a && a <= c){
		swap(a, b);
	}else if(b <= c && c <= a){
		swap(a, b);
		swap(b, c);
	}else if(c <= a && a <= b){
		swap(b, c);
		swap(a, b);
	}else if(c <= b && b <= a){
		swap(a, c);
	}
}

bool equalize(int a, int b, int c){
	queue<int> q;
	bool visited[MAX][MAX][MAX] = {};
	q.push(a);
	q.push(b);
	q.push(c);
	visited[a][b][c] = true;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		int z = q.front();
		q.pop();
		if(x == y && y == z){
			return true;
		}
		if(x != y){
			int nx = x + x, ny = y - x, nz = z;
			order(nx, ny, nz);
			if(!visited[nx][ny][nz]){
				q.push(nx);
				q.push(ny);
				q.push(nz);
				visited[nx][ny][nz] = true;
			}
		}
		if(y != z){
			int nx = x, ny = y + y, nz = z - y;
			order(nx, ny, nz);
			if(!visited[nx][ny][nz]){
				q.push(nx);
				q.push(ny);
				q.push(nz);
				visited[nx][ny][nz] = true;
			}
		}
		int nx = x + x, ny = y, nz = z - x;
		order(nx, ny, nz);
		if(!visited[nx][ny][nz]){
			q.push(nx);
			q.push(ny);
			q.push(nz);
			visited[nx][ny][nz] = true;
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b, c;
	cin >> a >> b >> c;
	order(a, b, c);
	cout << equalize(a, b, c);
	return 0;
}
