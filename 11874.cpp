#include <cstdio>

int sumOfDigits(int n){
	int ret = 0;
	while(n > 0){
		ret += n % 10;
		n /= 10;
	}
	return ret;
}

int main(){
	int l, d, x;
	scanf("%d %d %d", &l, &d, &x);
	for(int n = l; n <= d; ++n){
		if(sumOfDigits(n) == x){
			printf("%d\n", n);
			break;
		}
	}
	for(int m = d; m >= l; --m){
		if(sumOfDigits(m) == x){
			printf("%d\n", m);
			break;
		}
	}
	return 0;
}
