#include <cstdio>
#include <vector>
#include <tuple>
#define MAX 22

using namespace std;

int word_length_right(char puzzle[][MAX], bool visited[][MAX][2], int r, int c, int x, int y){
	if(visited[x][y][0]){
		return 0;
	}
	int ret = 0;
	while(y < c && puzzle[x][y] != '@'){
		visited[x][y][0] = true;
		++ret;
		++y;
	}
	return ret;
}

int word_length_down(char puzzle[][MAX], bool visited[][MAX][2], int r, int c, int x, int y){
	if(visited[x][y][1]){
		return 0;
	}
	int ret = 0;
	while(x < r && puzzle[x][y] != '@'){
		visited[x][y][1] = true;
		++ret;
		++x;
	}
	return ret;
}

int main(){
	int t = 0;
	while(true){
		int r, c;
		scanf("%d %d", &r, &c);
		if(r == 0 && c == 0){
			break;
		}
		++t;
		char puzzle[MAX][MAX];
		for(int i = 0; i < r; ++i){
			scanf("%s", puzzle[i]);
		}
		bool visited[MAX][MAX][2] = {};
		int number = 1;
		vector<pair<int, int>> a, b;
		for(int i = 0; i < r; ++i){
			for(int j = 0; j < c; ++j){
				if(puzzle[i][j] == '@'){
					continue;
				}
				int right = word_length_right(puzzle, visited, r, c, i, j);
				int down = word_length_down(puzzle, visited, r, c, i, j);
				if(right >= 3 || down >= 3){
					if(right >= 3){
						a.push_back(make_pair(number, right));
					}
					if(down >= 3){
						b.push_back(make_pair(number, down));
					}
					++number;
				}
			}
		}
		printf("Crossword puzzle %d\n", t);
		printf("Across\n");
		for(pair<int, int> p : a){
			if(p.first >= 10){
				printf("%d. (%d)\n", p.first, p.second);
			}else{
				printf("%d.  (%d)\n", p.first, p.second);
			}
		}
		printf("Down\n");
		for(pair<int, int> p : b){
			if(p.first >= 10){
				printf("%d. (%d)\n", p.first, p.second);
			}else{
				printf("%d.  (%d)\n", p.first, p.second);
			}
		}
		printf("\n");
	}
	return 0;
}
