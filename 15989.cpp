#include <cstdio>
#define MAX 10001

long long ways(int number){
	long long a[MAX][4] = {}; // a[n][i]: # of ways to reach n with largest summand <= i
	a[1][1] = 1;
	a[1][2] = 1;
	a[1][3] = 1;
	a[2][1] = 1;
	a[2][2] = 2;
	a[2][3] = 2;
	a[3][1] = 1;
	a[3][2] = 2;
	a[3][3] = 3;
	for(int n = 4; n <= number; ++n){
		a[n][1] = a[n-1][1];
		a[n][2] = a[n-2][2] + a[n-1][1];
		a[n][3] = a[n-3][3] + a[n-2][2] + a[n-1][1];
	}
	return a[number][3];
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
