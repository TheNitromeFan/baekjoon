#include <cstdio>
#include <vector>
#include <utility>
#define MAX 51

using namespace std;

bool valid_col(char grid[][MAX], int n, int x, int y){
	if(x > 0 && grid[x - 1][y] == '.'){
		return false;
	}
	return x + 2 < n && grid[x][y] == '.' && grid[x + 1][y] == '.' && grid[x + 2][y] == '.';
}

bool valid_row(char grid[][MAX], int m, int x, int y){
	if(y > 0 && grid[x][y - 1] == '.'){
		return false;
	}
	return y + 2 < m && grid[x][y] == '.' && grid[x][y + 1] == '.' && grid[x][y + 2] == '.';
}

bool valid(char grid[][MAX], int n, int m, int x, int y){
	return valid_col(grid, n, x, y) || valid_row(grid, m, x, y);
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	char board[MAX][MAX];
	for(int i = 0; i < n; ++i){
		scanf("%s", board[i]);
	}
	vector<pair<int, int>> ans;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(valid(board, n, m, i, j)){
				ans.push_back(make_pair(i + 1, j + 1));
			}
		}
	}
	printf("%llu", ans.size());
	for(pair<int, int> p : ans){
		printf("\n%d %d", p.first, p.second);
	}
	return 0;
}
