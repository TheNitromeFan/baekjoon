#include <cstdio>

int main(){
	int sums[80001] = {};
	for(int i = 3; i <= 80000; ++i){
		sums[i] = sums[i-1];
		if(i % 3 == 0 || i % 7 == 0){
			sums[i] += i;
		}
	}
	int t;
	scanf("%d", &t);
	for(int a = 0; a < t; ++a){
		int n;
		scanf("%d", &n);
		printf("%d\n", sums[n]);
	}
	return 0;
}
