#include <cstdio>
#include <cmath>

bool is_square(int n){
	int x = (int)sqrt(n);
	return (x-2)*(x-2) == n || (x-1)*(x-1) == n || x*x == n || (x+1)*(x+1) == n || (x+2)*(x+2) == n;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	if(n == 0 || m == 0){
		printf("-1");
		return 0;
	}
	char num[11][11];
	for(int i = 0; i < n; ++i){
		scanf("%s", num[i]);
	}
	int ans = -1;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			for(int x = -i; x < n-i; ++x){
				for(int y = -j; y < m-j; ++y){
					int tmp = 0;
					if(x != 0 || y != 0){
						int c = 0;
						while(i+c*x >= 0 && i+c*x < n && j+c*y >= 0 && j+c*y < m){
							tmp *= 10;
							tmp += num[i+c*x][j+c*y] - '0';
							++c;
							if(is_square(tmp) && tmp > ans){
								ans = tmp;
							}
						}
					}else{
						tmp = num[i][j] - '0';
					}
					if(is_square(tmp) && tmp > ans){
						ans = tmp;
					}
				}
			}
		}
	}
	printf("%d", ans);
	return 0;
}
