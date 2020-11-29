#include <cstdio>
#define MOD 1000000007

void multiply(long long a[4], long long b[4]){
	long long c[4] = {};
	c[0] = (a[0] * b[0] + a[1] * b[2]) % MOD;
	c[1] = (a[0] * b[1] + a[1] * b[3]) % MOD;
	c[2] = (a[2] * b[0] + a[3] * b[2]) % MOD;
	c[3] = (a[2] * b[1] + a[3] * b[3]) % MOD;
	a[0] = c[0];
	a[1] = c[1];
	a[2] = c[2];
	a[3] = c[3];
}

void power(long long a[4], long long n){
	if(n == 0){
		a[0] = 1;
		a[1] = 0;
		a[2] = 0;
		a[3] = 1;
	}else if(n % 2 == 0){
		power(a, n / 2);
		multiply(a, a);
	}else{
		long long b[4];
		b[0] = a[0];
		b[1] = a[1];
		b[2] = a[2];
		b[3] = a[3];
		power(a, n / 2);
		multiply(a, a);
		multiply(a, b);
	}
}

int main(){
	long long n;
	scanf("%lld", &n);
	if(n % 2 == 1){
		printf("0");
		return 0;
	}
	long long mat[4] = {4, -1, 1, 0};
	power(mat, n / 2);
	long long ans = (mat[2] * 3 + mat[3] * 1) % MOD;
	while(ans < 0){
		ans += MOD;
	}
	printf("%lld", ans);
	return 0;
}
