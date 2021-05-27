#include <cstdio>
#include <algorithm>
#define MAX 1001

void initialize_psum(char map[][MAX], int psum[][MAX], int n, int m){
	if(map[0][0] == '*'){
		psum[0][0] = 1;
	}
	for(int j = 1; j < m; ++j){
		psum[0][j] = psum[0][j - 1];
		if(map[0][j] == '*'){
			++psum[0][j];
		}
	}
	for(int i = 1; i < n; ++i){
		psum[i][0] = psum[i - 1][0];
		if(map[i][0] == '*'){
			++psum[i][0];
		}
	}
	for(int i = 1; i < n; ++i){
		for(int j = 1; j < m; ++j){
			psum[i][j] = psum[i][j - 1] + psum[i - 1][j] - psum[i - 1][j - 1];
			if(map[i][j] == '*'){
				++psum[i][j];
			}
		}
	}
}

bool match(char number[][4], char map[][MAX], int psum[][MAX], int k, int x, int y){
	for(int i = 0; i < 5; ++i){
		for(int j = 0; j < 3; ++j){
			int asterisks = psum[x + i * k + k - 1][y + j * k + k - 1];
			if(x + i * k - 1 >= 0){
				asterisks -= psum[x + i * k - 1][y + j * k + k - 1];
			}
			if(y + j * k - 1 >= 0){
				asterisks -= psum[x + i * k + k - 1][y + j * k - 1];
			}
			if(x + i * k - 1 >= 0 && y + j * k - 1 >= 0){
				asterisks += psum[x + i * k - 1][y + j * k - 1];
			}
			if(!(number[i][j] == map[x + i * k][y + j * k]
			&& (asterisks == k * k || asterisks == 0))){
				return false;
			}
		}
	}
	return true;
}

int main(){
	char numbers[10][5][4] = {
		{
			"***",
			"* *",
			"* *",
			"* *",
			"***"
		},
		{
			"** ",
			" * ",
			" * ",
			" * ",
			"***"
		},
		{
			"** ",
			"  *",
			" * ",
			"*  ",
			"***"
		},
		{
			"***",
			"  *",
			" **",
			"  *",
			"***"
		},
		{
			"  *",
			" **",
			"* *",
			"***",
			"  *"
		},
		{
			"***",
			"*  ",
			"** ",
			"  *",
			"***"
		},
		{
			"*  ",
			"*  ",
			"***",
			"* *",
			"***"
		},
		{
			"***",
			"  *",
			" * ",
			"*  ",
			"*  "
		},
		{
			"***",
			"* *",
			"***",
			"* *",
			"***"
		},
		{
			"***",
			"* *",
			"***",
			"  *",
			"  *"
		}
	};
	int n, m;
	scanf("%d %d", &n, &m);
	char map[MAX][MAX];
	fgets(map[0], MAX, stdin);
	for(int i = 0; i < n; ++i){
		fgets(map[i], MAX, stdin);
	}
	int psum[MAX][MAX] = {};
	initialize_psum(map, psum, n, m);
	for(int k = std::min(n / 5, m / 3); k > 0; --k){
		for(int x = 0; x + 5 * k <= n; ++x){
			for(int y = 0; y + 3 * k <= m; ++y){
				for(int digit = 0; digit < 10; ++digit){
					if(match(numbers[digit], map, psum, k, x, y)){
						printf("%d", digit);
						return 0;
					}
				}
			}
		}
	}
	return 0;
}
