#include <cstdio>

int t(int n){
	return n * (n + 1) / 2;
}

bool possible(int n){
	for(int i = 1; t(i) <= n; ++i){
		for(int j = 1; j <= i; ++j){
			for(int k = 1; k <= j; ++k){
				if(n == t(i) + t(j) + t(k)){
					return true;
				}
			}
		}
	}
	return false;
}

int main(){
	int tc;
	scanf("%d", &tc);
	for(int i = 0; i < tc; ++i){
		int n;
		scanf("%d", &n);
		printf("%d\n", possible(n));
	}
	return 0;
}
