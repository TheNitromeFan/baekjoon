#include <cstdio>
#define MAX 40

bool ladder(bool connected[][MAX], int n, int h){
	for(int j = 1; j <= n; ++j){
		int pos = j;
		for(int i = 1; i <= h; ++i){
			if(connected[i][pos]){
				++pos;
			}else if(connected[i][pos - 1]){
				--pos;
			}
		}
		if(pos != j){
			return false;
		}
	}
	return true;
}

void backtrack(bool connected[][MAX], int n, int h, int current_height, int cnt, int &ans){
	if(cnt > 3){
		return;
	}
	if(ladder(connected, n, h) && (ans == -1 || ans > cnt)){
		ans = cnt;
		return;
	}
	for(int i = current_height; i <= h; ++i){
		for(int j = 1; j < n; ++j){
			if(connected[i][j - 1] || connected[i][j] || connected[i][j + 1]){
				continue;
			}
			connected[i][j] = true;
			backtrack(connected, n, h, i, cnt + 1, ans);
			connected[i][j] = false;
		}
	}
}

int main(){
	int n, m, h;
	scanf("%d %d %d", &n, &m, &h);
	bool connected[MAX][MAX] = {};
	for(int i = 0; i < m; ++i){
		int a, b;
		scanf("%d %d", &a, &b); // height a, position b ~ b+1
		connected[a][b] = true;
	}
	int ans = -1;
	backtrack(connected, n, h, 1, 0, ans);
	printf("%d", ans);
	return 0;
}
