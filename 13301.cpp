#include <cstdio>

int main(){
	long long fibs[82] = {1, 1};
	for(int i = 2; i <= 81; ++i){
		fibs[i] = fibs[i - 1] + fibs[i - 2];
	}
	int n;
	scanf("%d", &n);
	printf("%lld", 2 * fibs[n + 1]);
	return 0;
}
