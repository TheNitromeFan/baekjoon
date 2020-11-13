#include <cstdio>

int main(){
	long long k, a, b;
	scanf("%lld %lld %lld", &k, &a, &b);
	if(a > 0){
		printf("%lld", b / k - (a - 1) / k);
	}else if(b < 0){
		printf("%lld", (-a) / k - (-b - 1) / k);
	}else{
		printf("%lld", b / k + (-a) / k + 1);
	}
	return 0;
}
