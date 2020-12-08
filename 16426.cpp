#include <iostream>
#define MAX 100

using namespace std;

bool drain(int h[][MAX], int r, int c, int x, int y){
	if(x == 0 || x == r - 1 || y == 0 || y == c - 1){
		return false;
	}
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	for(int i = 0; i < 4; ++i){
		int nx = x + dx[i], ny = y + dy[i];
		if(h[nx][ny] <= h[x][y]){
			return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int r, c;
	cin >> r >> c;
	int h[MAX][MAX];
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			cin >> h[i][j];
		}
	}
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			cout << drain(h, r, c, i, j) << ' ';
		}
		cout << '\n';
	}
	return 0;
}
