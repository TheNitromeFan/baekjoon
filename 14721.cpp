#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int x[100], y[100];
	for(int i = 0; i < n; ++i){
		scanf("%d %d", &x[i], &y[i]);
	}
	long long minRSS = 1000000000000000000LL;
	int minA = 0, minB = 0;
	for(int a = 1; a <= 100; ++a){
		for(int b = 1; b <= 100; ++b){
			long long RSS = 0;
			for(int i = 0; i < n; ++i){
				RSS += (long long)(y[i] - a * x[i] - b) * (y[i] - a * x[i] - b);
			}
			if(minRSS > RSS){
				minRSS = RSS;
				minA = a;
				minB = b;
			}
		}
	}
	printf("%d %d", minA, minB);
	return 0;
}
