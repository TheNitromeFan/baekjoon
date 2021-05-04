#include <iostream>
#define MAX 7

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool can_see(char hall[][MAX], int n, int x, int y){
	for(int dir = 0; dir < 4; ++dir){
		for(int i = x, j = y;
		i >= 0 && i < n && j >= 0 && j < n && hall[i][j] != 'O';
		i += dx[dir], j += dy[dir]){
			if(hall[i][j] == 'S'){
				return true;
			}
		}
	}
	return false;
}

bool check(char hall[][MAX], int n){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(hall[i][j] == 'T' && can_see(hall, n, i, j)){
				return false;
			}
		}
	}
	return true;
}

bool cover(char hall[][MAX], int n, int obs, int pos){
	if(pos == n * n){
		return obs == 0 && check(hall, n);
	}
	int x = pos / n, y = pos % n;
	if(obs > 0 && hall[x][y] == 'X'){
		hall[x][y] = 'O';
		--obs;
		if(cover(hall, n, obs, pos + 1)){
			return true;
		}
		++obs;
		hall[x][y] = 'X';
	}
	return cover(hall, n, obs, pos + 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	char hall[MAX][MAX];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cin >> hall[i][j];
		}
	}
	cout << (cover(hall, n, 3, 0) ? "YES" : "NO");
	return 0;
}
