#include <cstdio>

int main(){
	while(true){
		long long n;
		scanf("%lld", &n);
		if(n == 0){
			break;
		}
		printf("%lld\n", n * (n + 1) * (n + 2) / 6);
	}
	return 0;
}
