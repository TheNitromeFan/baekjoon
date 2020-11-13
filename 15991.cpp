#include <cstdio>
#define MAX 100001
#define MOD 1000000009

int ways(int number){
	static int a[MAX] = {};
	a[0] = 1;
	a[1] = 1;
	a[2] = 2;
	a[3] = 2;
	a[4] = 3;
	a[5] = 3;
	for(int n = 6; n <= number; ++n){
		a[n] = ((a[n-2] + a[n-4]) % MOD + a[n-6]) % MOD;
	}
	return a[number];
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
