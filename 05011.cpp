#include <cstdio>
#include <queue>
#define MAX 1001
#define MOD ((1LL << 31) - 1)

using namespace std;

long long shortest(char map[][MAX], int n){
	if(map[0][0] == '#'){
		return 0;
	}
	long long dp[MAX][MAX] = {};
	dp[0][0] = 1;
	for(int j = 1; j < n; ++j){
		if(map[0][j] == '#'){
			break;
		}
		dp[0][j] = 1;
	}
	for(int i = 1; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(map[i][j] == '#'){
				continue;
			}
			if(i > 0){
				dp[i][j] += dp[i - 1][j];
			}
			if(j > 0){
				dp[i][j] += dp[i][j - 1];
			}
			dp[i][j] %= MOD;
		}
	}
	return dp[n - 1][n - 1];
}

bool bfs(char map[][MAX], int n){
	if(map[0][0] == '#'){
		return false;
	}
	bool visited[MAX][MAX] = {};
	queue<int> q;
	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {1, 0, -1, 0};
	visited[0][0] = true;
	q.push(0);
	q.push(0);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		if(x == n - 1 && y == n - 1){
			return true;
		}
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx >= 0 && nx < n && ny >= 0 && ny < n && map[nx][ny] == '.' && !visited[nx][ny]){
				visited[nx][ny] = true;
				q.push(nx);
				q.push(ny);
			}
		}
	}
	return false;
}

int main(){
	int n;
	scanf("%d", &n);
	char map[MAX][MAX];
	for(int i = 0; i < n; ++i){
		scanf("%s", map[i]);
	}
	long long ans = shortest(map, n);
	if(ans > 0){
		printf("%lld", ans);
	}else if(bfs(map, n)){
		printf("THE GAME IS A LIE");
	}else{
		printf("INCONCEIVABLE");
	}
	return 0;
}
