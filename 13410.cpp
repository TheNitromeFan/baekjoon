#include <cstdio>

int reverse(int number){
	int ret = 0;
	while(number){
		ret = ret * 10 + number % 10;
		number /= 10;
	}
	return ret;
}

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	int ans = 0;
	for(int i = 1; i <= k; ++i){
		int cmp = reverse(n * i);
		if(ans < cmp){
			ans = cmp;
		}
	}
	printf("%d", ans);
	return 0;
}
