#include <cstdio>
#define MAX 100001
#define MOD 1000000009

int ways(int number){
	static int a[MAX][4] = {}; // a[n][i]: # of ways to reach n with last summand i
	a[1][1] = 1;
	a[2][2] = 1;
	a[3][1] = 1;
	a[3][2] = 1;
	a[3][3] = 1;
	for(int n = 4; n <= number; ++n){
		a[n][1] = (a[n-1][2] + a[n-1][3]) % MOD;
		a[n][2] = (a[n-2][1] + a[n-2][3]) % MOD;
		a[n][3] = (a[n-3][1] + a[n-3][2]) % MOD;
	}
	return ((a[number][1] + a[number][2]) % MOD + a[number][3]) % MOD;
}
int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++){
		int n;
		scanf("%d", &n);
		printf("%d\n", ways(n));
	}
	return 0;
}
