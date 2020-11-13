#include <cstdio>
#define MAX 1001
#define MOD 1000000009

int ways(int number, int cnt){
	static int a[MAX][MAX] = {}; // a[n][m]
	a[1][1] = 1;
	a[2][1] = 1;
	a[2][2] = 1;
	a[3][1] = 1;
	a[3][2] = 2;
	a[3][3] = 1;
	for(int n = 4; n <= number; ++n){
		for(int m = 1; m <= cnt; ++m){
			a[n][m] = ((a[n-1][m-1] + a[n-2][m-1]) % MOD + a[n-3][m-1]) % MOD;
		}
	}
	return a[number][cnt];
}
int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++){
		int n, m;
		scanf("%d %d", &n, &m);
		printf("%d\n", ways(n, m));
	}
	return 0;
}
