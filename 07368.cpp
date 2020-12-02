#include <cstdio>

bool overlap(int windows[][4], int i, int j){
	if(i == j || windows[i][0] > windows[j][2] || windows[i][2] < windows[j][0]
	|| windows[i][1] > windows[j][3] || windows[i][3] < windows[j][1]){
		return false;
	}
	return true;
}

int main(){
	while(true){
		int n;
		scanf("%d", &n);
		if(n == 0){
			break;
		}
		int windows[50][4];
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < 4; ++j){
				scanf("%d", &windows[i][j]);
			}
			windows[i][2] += windows[i][0] - 1;
			windows[i][3] += windows[i][1] - 1;
		}
		int ans = 0;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				if(overlap(windows, i, j)){
					++ans;
					break;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
