#include <cstdio>
#define MAX 1000001
#define MOD 1000000009

int ways(int number){
	static int a[MAX] = {0, 1, 2, 4};
	for(int i = 4; i <= number; i++)
		a[i] = ((a[i-1] + a[i-2]) % MOD + a[i-3]) % MOD;
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
