#include <cstdio>
#define MAX 100

void copy(int src[][MAX], int dest[][MAX], int n){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			dest[i][j] = src[i][j];
		}
	}
}

void rotate(int a[][MAX], int n){
	int tmp[MAX][MAX];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			tmp[i][j] = a[j][n - 1 - i];
		}
	}
	copy(tmp, a, n);
}

bool valid(int a[][MAX], int n){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n - 1; ++j){
			if(a[i][j] >= a[i][j + 1]){
				return false;
			}
		}
	}
	for(int j = 0; j < n; ++j){
		for(int i = 0; i < n - 1; ++i){
			if(a[i][j] >= a[i + 1][j]){
				return false;
			}
		}
	}
	return true;
}

int main(){
	int n;
	scanf("%d", &n);
	int sun[MAX][MAX];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			scanf("%d", &sun[i][j]);
		}
	}
	while(!valid(sun, n)){
		rotate(sun, n);
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			printf("%d ", sun[i][j]);
		}
		printf("\n");
	}
	return 0;
}
