#include <cstdio>
#define MAX 102

int main(){
	int r, s, k;
	scanf("%d %d %d", &r, &s, &k);
	char window[MAX][MAX];
	for(int i = 0; i < r; ++i){
		scanf("%s", window[i]);
	}
	int dp[MAX][MAX] = {};
	if(window[0][0] == '*'){
		dp[0][0] = 1;
	}
	for(int j = 1; j < s; ++j){
		dp[0][j] = dp[0][j - 1];
		if(window[0][j] == '*'){
			++dp[0][j];
		}
	}
	for(int i = 1; i < r; ++i){
		dp[i][0] = dp[i - 1][0];
		if(window[i][0] == '*'){
			++dp[i][0];
		}
	}
	for(int i = 1; i < r; ++i){
		for(int j = 1; j < s; ++j){
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1];
			if(window[i][j] == '*'){
				++dp[i][j];
			}
		}
	}
	int x = -1, y = -1;
	int max_flies = -1;
	for(int i = 0; i + k <= r; ++i){
		for(int j = 0; j + k <= s; ++j){
			int flies = dp[i + k - 2][j + k - 2] - dp[i + k - 2][j] - dp[i][j + k - 2] + dp[i][j];
			if(flies > max_flies){
				max_flies = flies;
				x = i;
				y = j;
			}
		}
	}
	window[x][y] = '+';
	window[x][y + k - 1] = '+';
	window[x + k - 1][y] = '+';
	window[x + k - 1][y + k - 1] = '+';
	for(int j = y + 1; j <= y + k - 2; ++j){
		window[x][j] = '-';
		window[x + k - 1][j] = '-';
	}
	for(int i = x + 1; i <= x + k - 2; ++i){
		window[i][y] = '|';
		window[i][y + k - 1] = '|';
	}
	printf("%d\n", max_flies);
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < s; ++j){
			printf("%c", window[i][j]);
		}
		printf("\n");
	}
	return 0;
}
