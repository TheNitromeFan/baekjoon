#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	long long a[51];
	for(int i = 0; i < n; ++i){
		scanf("%lld", &a[i]);
	}
	if(2 * a[1] == a[0] + a[2]){
		a[n] = a[n - 1] + a[1] - a[0];
	}else{
		a[n] = a[n - 1] * a[1] / a[0];
	}
	printf("%lld", a[n]);
	return 0;
}
