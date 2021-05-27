#include <cstdio>
#include <algorithm>
#define MAX 20

using std::max;

int main(){
	int scores[6][6] =
	{
		{10, 8, 7, 5, 0, 1},
		{8, 6, 4, 3, 0, 1},
		{7, 4, 3, 2, 0, 1},
		{5, 3, 2, 2, 0, 1},
		{0, 0, 0, 0, 0, 0},
		{1, 1, 1, 1, 0, 0}
	};
	int n, m;
	scanf("%d %d", &n, &m);
	char map[MAX][MAX];
	for(int i = 0; i < n; ++i){
		scanf("%s", map[i]);
	}
	int dp[MAX * MAX][1 << 14];
	for(int i = 0; i < n * m; ++i){
		for(int j = 0; j < (1 << m); ++j){
			dp[i + 1][j >> 1] = max(dp[i + 1][j >> 1], dp[i][j]);
			if(!(j & 1)){
				dp[i + 1][(j >> 1) + (1 << (m - 1))] = max(dp[i + 1][(j >> 1) + (1 << (m - 1))], dp[i][j]);
				dp[i + 1][(j >> 1) + (1 << (m - 1))] = max(dp[i + 1][(j >> 1) + (1 << (m - 1))], dp[i][j] + scores[map[i / m][i % m] - 'A'][map[i / m + 1][i % m] - 'A']);
			}
			if(!(j & 3) && i % m != m - 1){
				dp[i + 1][(j >> 1) + 1] = max(dp[i + 1][(j >> 1) + 1], dp[i][j]);
				dp[i + 1][(j >> 1) + 1] = max(dp[i + 1][(j >> 1) + 1], dp[i][j] + scores[map[i / m][i % m] - 'A'][map[i / m][i % m + 1] - 'A']);
			}
		}
	}
	printf("%d", dp[n * m][0]);
	return 0;
}
