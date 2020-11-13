#include <cstdio>

int findK(long long n){
	bool a[10] = {};
	int cnt = 0;
	for(int k = 1; ; ++k){
		long long m = k * n;
		while(m > 0){
			if(!a[m % 10]){
				a[m % 10] = true;
				++cnt;
			}
			m /= 10;
		}
		if(cnt == 10){
			return k;
		}
	}
}

int main(){
	long long n;
	while(scanf("%lld", &n) == 1){
		printf("%d\n", findK(n));
	}
	return 0;
}
