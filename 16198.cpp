#include <cstdio>

int power(int a[11], int n){
	if(n == 2){
		return 0;
	}
	int ret = 0;
	for(int i = 2; i < n; ++i){
		int b[11];
		int idx = 1;
		for(int j = 1; j <= n; ++j){
			if(i == j){
				continue;
			}
			b[idx] = a[j];
			++idx;
		}
		int cmp = a[i - 1] * a[i + 1] + power(b, n - 1);
		if(ret < cmp){
			ret = cmp;
		}
	}
	return ret;
}

int main(){
	int n;
	scanf("%d", &n);
	int marble[11];
	for(int i = 1; i <= n; ++i){
		scanf("%d", &marble[i]);
	}
	printf("%d", power(marble, n));
	return 0;
}
