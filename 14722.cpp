#include <cstdio>
#include <utility>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	static int map[1000][1000];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			scanf("%d", &map[i][j]);
		}
	}
	static pair<int, int> dp[1000][1000]; // first: max count, second: next milk
	if(map[0][0] == 0){
		dp[0][0].first = 1;
		dp[0][0].second = 1;
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(i == 0 && j == 0){
				continue;
			}else if(i == 0){
				if(dp[0][j-1].second == map[0][j]){
					dp[0][j].first = dp[0][j-1].first + 1;
					dp[0][j].second = (dp[0][j-1].second + 1) % 3;
				}else{
					dp[0][j].first = dp[0][j-1].first;
					dp[0][j].second = dp[0][j-1].second;
				}
			}else if(j == 0){
				if(dp[i-1][0].second == map[i][0]){
					dp[i][0].first = dp[i-1][0].first + 1;
					dp[i][0].second = (dp[i-1][0].second + 1) % 3;
				}else{
					dp[i][0].first = dp[i-1][0].first;
					dp[i][0].second = dp[i-1][0].second;
				}
			}else{
				int c1 = dp[i][j-1].first + (dp[i][j-1].second == map[i][j] ? 1 : 0);
				int c2 = dp[i-1][j].first + (dp[i-1][j].second == map[i][j] ? 1 : 0);
				if(c1 > c2){
					dp[i][j].first = dp[i][j-1].first + (dp[i][j-1].second == map[i][j] ? 1 : 0);
					dp[i][j].second = (dp[i][j-1].second == map[i][j] ? (dp[i][j-1].second + 1) % 3 : dp[i][j-1].second);
				}else{
					dp[i][j].first = dp[i-1][j].first + (dp[i-1][j].second == map[i][j] ? 1 : 0);
					dp[i][j].second = (dp[i-1][j].second == map[i][j] ? (dp[i-1][j].second + 1) % 3 : dp[i-1][j].second);
				}
			}
		}
	}
	printf("%d", dp[n-1][n-1].first);
	return 0;
}
