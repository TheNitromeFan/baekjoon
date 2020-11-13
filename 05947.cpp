#include <cstdio>

bool filter(int test[][51], int q[10], int a[10], int i, int p){
	for(int j = 0; j < p; ++j){
		if(test[i][q[j]] != a[j]){
			return false;
		}
	}
	return true;
}

int main(){
	int n, nq, p;
	scanf("%d %d %d", &n, &nq, &p);
	static int test[50000][51];
	for(int i = 0; i < n; ++i){
		for(int j = 1; j <= nq; ++j){
			scanf("%d", &test[i][j]);
		}
	}
	int q[10], a[10];
	for(int k = 0; k < p; ++k){
		scanf("%d %d", &q[k], &a[k]);
	}
	int cnt = 0;
	for(int i = 0; i < n; ++i){
		if(filter(test, q, a, i, p)){
			++cnt;
		}
	}
	printf("%d", cnt);
	return 0;
}
