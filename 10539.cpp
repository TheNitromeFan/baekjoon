#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	long long a[101], b[101];
	for(int i = 1; i <= n; ++i){
		scanf("%lld", &b[i]);
		a[i] = i * b[i];
		for(int j = 1; j < i; ++j){
			a[i] -= a[j];
		}
		printf("%lld ", a[i]);
	}
	return 0;
}
