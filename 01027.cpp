#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int b[51];
	for(int i = 1; i <= n; ++i){
		scanf("%d", &b[i]);
	}
	double slope[51][51] = {}; // slope[i][j]: from i to j
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			if(i != j){
				slope[i][j] = (b[i] - b[j]) / (double)(i - j);
			}
		}
	}
	int mx = 0;
	for(int i = 1; i <= n; ++i){
		int cnt = 0;
		for(int j = i-1; j > 0; --j){
			bool can_see = true;
			for(int k = i-1; k > j; --k){
				if(slope[i][k] <= slope[i][j]){
					can_see = false;
					break;
				}
			}
			if(can_see){
				++cnt;
			}
		}
		for(int j = i+1; j <= n; ++j){
			bool can_see = true;
			for(int k = i+1; k < j; ++k){
				if(slope[i][k] >= slope[i][j]){
					can_see = false;
					break;
				}
			}
			if(can_see){
				++cnt;
			}
		}
		// printf("%d cnt: %d\n", i, cnt);
		if(cnt > mx){
			mx = cnt;
		}
	}
	printf("%d", mx);
	return 0;
}
