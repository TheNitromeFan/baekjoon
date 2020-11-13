#include <cstdio>

int sum_of_digits(int n){
	int ret = 0;
	while(n){
		ret += n % 10;
		n /= 10;
	}
	return ret;
}

bool good(int n){
	return n % sum_of_digits(n) == 0;
}

int main(){
	int n;
	scanf("%d", &n);
	int ans = 0;
	for(int i = 1; i <= n; ++i){
		if(good(i)){
			++ans;
		}
	}
	printf("%d", ans);
	return 0;
}
