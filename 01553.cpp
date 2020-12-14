#include <iostream>
#include <map>
#include <utility>
#include <string>

using namespace std;

int fill_board(int grid[][7], map<pair<int, int>, bool> &dominoes, bool visited[][7], int x, int y){
	if(x == 8){
		return 1;
	}
	if(visited[x][y]){
		++y;
		if(y == 7){
			++x;
			y = 0;
		}
		return fill_board(grid, dominoes, visited, x, y);
	}
	int ret = 0;
	if(x < 7 && !visited[x + 1][y]){
		visited[x][y] = true;
		visited[x + 1][y] = true;
		if(grid[x][y] != grid[x + 1][y]){
			if(dominoes[make_pair(grid[x][y], grid[x + 1][y])]){
				dominoes[make_pair(grid[x][y], grid[x + 1][y])] = false;
				ret += fill_board(grid, dominoes, visited, x, y);
				dominoes[make_pair(grid[x][y], grid[x + 1][y])] = true;
			}
			if(dominoes[make_pair(grid[x + 1][y], grid[x][y])]){
				dominoes[make_pair(grid[x + 1][y], grid[x][y])] = false;
				ret += fill_board(grid, dominoes, visited, x, y);
				dominoes[make_pair(grid[x + 1][y], grid[x][y])] = true;
			}
		}else{
			if(dominoes[make_pair(grid[x][y], grid[x + 1][y])]){
				dominoes[make_pair(grid[x][y], grid[x + 1][y])] = false;
				ret += fill_board(grid, dominoes, visited, x, y);
				dominoes[make_pair(grid[x][y], grid[x + 1][y])] = true;
			}
		}
		visited[x][y] = false;
		visited[x + 1][y] = false;
	}
	if(y < 6 && !visited[x][y + 1]){
		visited[x][y] = true;
		visited[x][y + 1] = true;
		if(grid[x][y] != grid[x][y + 1]){
			if(dominoes[make_pair(grid[x][y], grid[x][y + 1])]){
				dominoes[make_pair(grid[x][y], grid[x][y + 1])] = false;
				ret += fill_board(grid, dominoes, visited, x, y);
				dominoes[make_pair(grid[x][y], grid[x][y + 1])] = true;
			}
			if(dominoes[make_pair(grid[x][y + 1], grid[x][y])]){
				dominoes[make_pair(grid[x][y + 1], grid[x][y])] = false;
				ret += fill_board(grid, dominoes, visited, x, y);
				dominoes[make_pair(grid[x][y + 1], grid[x][y])] = true;
			}
		}else{
			if(dominoes[make_pair(grid[x][y], grid[x][y + 1])]){
				dominoes[make_pair(grid[x][y], grid[x][y + 1])] = false;
				ret += fill_board(grid, dominoes, visited, x, y);
				dominoes[make_pair(grid[x][y], grid[x][y + 1])] = true;
			}
		}
		visited[x][y] = false;
		visited[x][y + 1] = false;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	map<pair<int, int>, bool> dominoes;
	for(int i = 0; i <= 6; ++i){
		for(int j = 0; j <= i; ++j){
			dominoes[make_pair(j, i)] = true;
		}
	}
	int grid[8][7];
	for(int x = 0; x < 8; ++x){
		string s;
		cin >> s;
		for(int y = 0; y < 7; ++y){
			grid[x][y] = s[y] - '0';
		}
	}
	bool visited[8][7] = {};
	cout << fill_board(grid, dominoes, visited, 0, 0);
	return 0;
}
