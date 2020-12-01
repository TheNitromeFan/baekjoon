#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	long long a[101];
	a[0] = 0;
	for(int i = 1; i <= n; ++i){
		a[i] = a[i - 1] + 1;
		for(int j = 3; j <= i; ++j){
			if(a[i] < a[i - j] * (j - 1)){
				a[i] = a[i - j] * (j - 1);
			}
		}
	}
	printf("%lld", a[n]);
	return 0;
}
