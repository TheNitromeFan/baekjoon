#include <cstdio>

int ans(int n, int m, int k){
	for(int i = 0; i + m + k <= n; ++i){
		if(2 * (m + i) > n){
			return i;
		}
	}
	return -1;
}

int main(){
	while(true){
		int n, m, k;
		scanf("%d %d %d", &n, &m, &k);
		if(n == 0 && m == 0 && k == 0){
			break;
		}
		printf("%d\n", ans(n, m, k));
	}
	return 0;
}
