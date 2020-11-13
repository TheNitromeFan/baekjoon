#include <cstdio>

int mooCount(char puzzle[][51], int n, int m, char a, char b){
	if(a == 'M' || b == 'O' || a == b){
		return 0;
	}
	int ret = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(i + 2 < n && puzzle[i][j] == a && puzzle[i + 1][j] == b && puzzle[i + 2][j] == b){
				++ret;
			}
			if(i + 2 < n && j + 2 < m && puzzle[i][j] == a && puzzle[i + 1][j + 1] == b && puzzle[i + 2][j + 2] == b){
				++ret;
			}
			if(j + 2 < m && puzzle[i][j] == a && puzzle[i][j + 1] == b && puzzle[i][j + 2] == b){
				++ret;
			}
			if(i - 2 >= 0 && j + 2 < m && puzzle[i][j] == a && puzzle[i - 1][j + 1] == b && puzzle[i - 2][j + 2] == b){
				++ret;
			}
			if(i - 2 >= 0 && puzzle[i][j] == a && puzzle[i - 1][j] == b && puzzle[i - 2][j] == b){
				++ret;
			}
			if(i - 2 >= 0 && j - 2 >= 0 && puzzle[i][j] == a && puzzle[i - 1][j - 1] == b && puzzle[i - 2][j - 2] == b){
				++ret;
			}
			if(j - 2 >= 0 && puzzle[i][j] == a && puzzle[i][j - 1] == b && puzzle[i][j - 2] == b){
				++ret;
			}
			if(i + 2 < n && j - 2 >= 0 && puzzle[i][j] == a && puzzle[i + 1][j - 1] == b && puzzle[i + 2][j - 2] == b){
				++ret;
			}
		}
	}
	return ret;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	char puzzle[51][51];
	for(int i = 0; i < n; ++i){
		scanf("%s", puzzle[i]);
	}
	int maxCnt = 0;
	for(char a = 'A'; a <= 'Z'; ++a){
		for(char b = 'A'; b <= 'Z'; ++b){
			int cnt = mooCount(puzzle, n, m, a, b);
			if(maxCnt < cnt){
				maxCnt = cnt;
			}
		}
	}
	printf("%d", maxCnt);
	return 0;
}
