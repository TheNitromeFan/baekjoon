#include <cstdio>

void no4or7(long long low, long long high, long long n, long long &cnt){
	if(n > high){
		return;
	}else if(n >= low){
		++cnt;
	}
	no4or7(low, high, 10 * n + 4, cnt);
	no4or7(low, high, 10 * n + 7, cnt);
}

int main(){
	long long a, b;
	scanf("%lld %lld", &a, &b);
	long long cnt = 0;
	no4or7(a, b, 0, cnt);
	printf("%lld", cnt);
	return 0;
}
