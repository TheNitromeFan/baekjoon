#include <cstdio>
#include <cstdlib>
#define MAX 100000

int min_steps(int steps[MAX], int size){
	if(size == 0){
		return 0;
	}
	static int dp[5][5][MAX]; // dp[left][right][min_so_far]
	for(int i = 0; i < size; ++i){
		for(int left = 0; left <= 4; ++left){
			for(int right = 0; right <= 4; ++right){
				dp[left][right][i] = -1;
			}
		}
	}
	dp[steps[0]][0][0] = 2;
	dp[0][steps[0]][0] = 2;
	for(int i = 1; i < size; ++i){
		for(int right = 0; right <= 4; ++right){
			if(right == steps[i]){
				continue;
			}
			int tmp = -1;
			for(int left = 0; left <= 4; ++left){
				if(left == steps[i] && dp[left][right][i-1] != -1 && (tmp == -1 || tmp > dp[left][right][i-1] + 1)){
					tmp = dp[left][right][i-1] + 1;
				}else if(left == 0 && dp[left][right][i-1] != -1 && (tmp == -1 || tmp > dp[left][right][i-1] + 2)){
					tmp = dp[left][right][i-1] + 2;
				}else if(abs(left - steps[i]) != 2 && dp[left][right][i-1] != -1 && (tmp == -1 || tmp > dp[left][right][i-1] + 3)){
					tmp = dp[left][right][i-1] + 3;
				}else if(dp[left][right][i-1] != -1 && (tmp == -1 || tmp > dp[left][right][i-1] + 4)){
					tmp = dp[left][right][i-1] + 4;
				}
			}
			dp[steps[i]][right][i] = tmp;
		}
		for(int left = 0; left <= 4; ++left){
			if(left == steps[i]){
				continue;
			}
			int tmp = -1;
			for(int right = 0; right <= 4; ++right){
				if(right == steps[i] && dp[left][right][i-1] != -1 && (tmp == -1 || tmp > dp[left][right][i-1] + 1)){
					tmp = dp[left][right][i-1] + 1;
				}else if(right == 0 && dp[left][right][i-1] != -1 && (tmp == -1 || tmp > dp[left][right][i-1] + 2)){
					tmp = dp[left][right][i-1] + 2;
				}else if(abs(right - steps[i]) != 2 && dp[left][right][i-1] != -1 && (tmp == -1 || tmp > dp[left][right][i-1] + 3)){
					tmp = dp[left][right][i-1] + 3;
				}else if(dp[left][right][i-1] != -1 && (tmp == -1 || tmp > dp[left][right][i-1] + 4)){
					tmp = dp[left][right][i-1] + 4;
				}
			}
			dp[left][steps[i]][i] = tmp;
		}
		/*
		for(int left = 0; left <= 4; ++left){
			for(int right = 0; right <= 4; ++right){
				printf("%d ", dp[left][right][i]);
			}
			printf("\n");
		}
		printf("\n");
		*/
	}
	int ret = -1;
	for(int left = 0; left <= 4; ++left){
		for(int right = 0; right <= 4; ++right){
			if(dp[left][right][size-1] != -1 && (ret == -1 || ret > dp[left][right][size-1])){
				ret = dp[left][right][size-1];
			}
		}
	}
	return ret;
}

int main(){
	int steps[MAX];
	int index = 0;
	while(true){
		int x;
		scanf("%d", &x);
		if(x == 0){
			break;
		}
		steps[index] = x;
		++index;
	}
	printf("%d", min_steps(steps, index));
	return 0;
}
