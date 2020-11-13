#include <cstdio>

int bits(int n){
	int ret = 0;
	while(n){
		ret += n & 1;
		n >>= 1;
	}
	return ret;
}

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	int ans = 0;
	while(bits(n + ans) > k){
		++ans;
	}
	printf("%d", ans);
	return 0;
}
