#include <cstdio>
#define MAX 100

int main(){
	int n, ell;
	scanf("%d %d", &n, &ell);
	int map[MAX][MAX];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			scanf("%d", &map[i][j]);
		}
	}
	int ans = 0;
	bool flag, can_place;
	for(int i = 0; i < n; ++i){
		flag = true;
		bool wedge[MAX] = {};
		for(int j = 0; j < n - 1; ++j){
			if(map[i][j] == map[i][j + 1] + 1){
				can_place = true;
				for(int k = 1; k <= ell; ++k){
					if(j + k >= n || map[i][j + k] != map[i][j + 1] || wedge[j + k]){
						can_place = false;
						break;
					}
				}
				if(can_place){
					for(int k = 1; k <= ell; ++k){
						wedge[j + k] = true;
					}
				}else{
					flag = false;
					break;
				}
			}else if(map[i][j] + 1 == map[i][j + 1]){
				can_place = true;
				for(int k = 0; k < ell; ++k){
					if(j - k < 0 || map[i][j - k] != map[i][j] || wedge[j - k]){
						can_place = false;
						break;
					}
				}
				if(can_place){
					for(int k = 0; k < ell; ++k){
						wedge[j - k] = true;
					}
				}else{
					flag = false;
					break;
				}
			}else if(map[i][j] != map[i][j + 1]){
				flag = false;
				break;
			}
		}
		if(flag){
			++ans;
		}
	}
	for(int j = 0; j < n; ++j){
		flag = true;
		bool wedge[MAX] = {};
		for(int i = 0; i < n - 1; ++i){
			if(map[i][j] == map[i + 1][j] + 1){
				can_place = true;
				for(int k = 1; k <= ell; ++k){
					if(i + k >= n || map[i + k][j] != map[i + 1][j] || wedge[i + k]){
						can_place = false;
						break;
					}
				}
				if(can_place){
					for(int k = 1; k <= ell; ++k){
						wedge[i + k] = true;
					}
				}else{
					flag = false;
					break;
				}
			}else if(map[i][j] + 1 == map[i + 1][j]){
				can_place = true;
				for(int k = 0; k < ell; ++k){
					if(i - k < 0 || map[i - k][j] != map[i][j] || wedge[i - k]){
						can_place = false;
						break;
					}
				}
				if(can_place){
					for(int k = 0; k < ell; ++k){
						wedge[i - k] = true;
					}
				}else{
					flag = false;
					break;
				}
			}else if(map[i][j] != map[i + 1][j]){
				flag = false;
				break;
			}
		}
		if(flag){
			++ans;
		}
	}
	printf("%d", ans);
	return 0;
}
