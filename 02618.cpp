#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <algorithm>
#define MAX 2000

using namespace std;

int dp[MAX+2][MAX+2];
int choose[MAX+2][MAX+2];

int dist(pair<int, int> a, pair<int, int> b){
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int moves(pair<int, int> cases[MAX+2], int n, int m, int x, int y){
	if(dp[x][y] != -1){
		return dp[x][y];
	}
	int next = max(x, y) + 1;
	if(next == m + 2){
		return 0;
	}
	int cmp1 = moves(cases, n, m, next, y) + dist(cases[x], cases[next]);
	int cmp2 = moves(cases, n, m, x, next) + dist(cases[y], cases[next]);
	if(cmp1 < cmp2){
		dp[x][y] = cmp1;
		choose[x][y] = 1;
	}else{
		dp[x][y] = cmp2;
		choose[x][y] = 2;
	}
	return dp[x][y];
}

int main(){
	int n;
	scanf("%d", &n);
	int m;
	scanf("%d", &m);
	pair<int, int> cases[MAX+2];
	cases[0] = make_pair(1, 1);
	cases[1] = make_pair(n, n);
	for(int i = 2; i < m + 2; ++i){
		scanf("%d %d", &cases[i].first, &cases[i].second);
	}
	memset(dp, -1, sizeof(dp));
	printf("%d", moves(cases, n, m, 0, 1));
	for(int x = 0, y = 1; max(x, y) + 1 < m + 2;){
		printf("\n%d", choose[x][y]);
		if(choose[x][y] == 1){
			x = max(x, y) + 1;
		}else{
			y = max(x, y) + 1;
		}
	}
	return 0;
}
