#include <cstdio>

int factorial[6] = {1, 1, 2, 6, 24, 120};

int acm(int n){
	int ret = 0;
	int i = 1;
	while(n){
		ret += factorial[i] * (n % 10);
		++i;
		n /= 10;
	}
	return ret;
}

int main(){
	while(true){
		int n;
		scanf("%d", &n);
		if(n == 0){
			break;
		}
		printf("%d\n", acm(n));
	}
	return 0;
}
