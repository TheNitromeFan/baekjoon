#include <cstdio>
#include <cstdlib>

void rotate(int a[][400], int n){
	int c[400][400];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			c[i][j] = a[j][n - i - 1];
		}
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			a[i][j] = c[i][j];
		}
	}
}

void reflect(int a[][400], int n){
	int c[400][400];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			c[i][j] = a[i][n - 1 - j];
		}
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			a[i][j] = c[i][j];
		}
	}
}

int main(){
	while(true){
		int n;
		scanf("%d", &n);
		if(n == 0){
			break;
		}
		int a[400][400], b[400][400];
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				scanf("%d", &a[i][j]);
			}
		}
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				scanf("%d", &b[i][j]);
			}
		}
		int maxConf = 0;
		for(int a0 = 0; a0 < 4; ++a0){
			int conf = 0;
			for(int i = 0; i < n; ++i){
				for(int j = 0; j < n; ++j){
					if(abs(a[i][j] - b[i][j]) <= 100){
						++conf;
					}
				}
			}
			if(maxConf < conf){
				maxConf = conf;
			}
			rotate(a, n);
		}
		reflect(a, n);
		for(int a0 = 0; a0 < 4; ++a0){
			int conf = 0;
			for(int i = 0; i < n; ++i){
				for(int j = 0; j < n; ++j){
					if(abs(a[i][j] - b[i][j]) <= 100){
						++conf;
					}
				}
			}
			if(maxConf < conf){
				maxConf = conf;
			}
			rotate(a, n);
		}
		printf("%.2lf\n", maxConf * 100 / (double)(n * n));
	}
	return 0;
}
