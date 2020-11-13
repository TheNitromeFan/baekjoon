#include <cstdio>

int multiply(int a[][300], int b[][300], int n){
	int ans = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			for(int k = 0; k < n; ++k){
				if(a[i][k] && b[k][j]){
					++ans;
					break;
				}
			}
		}
	}
	return ans;
}

int main(){
	int n;
	scanf("%d", &n);
	static int a[300][300], b[300][300];
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
	printf("%d", multiply(a, b, n));
	return 0;
}
