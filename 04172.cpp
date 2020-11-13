#include <cstdio>
#include <cmath>
#define MOD 1000000

int main(){
	static int x[1000001] = {};
	x[0] = 1;
	int i = 1;
	while(true){
		int n;
		scanf("%d", &n);
		if(n == -1){
			break;
		}else if(n == 0){
			printf("1\n");
			continue;
		}
		for(; i <= n; ++i){
			x[i] = ((x[(int)floor(i - sqrt(i))] + x[(int)floor(log(i))]) % MOD + x[(int)floor(i * sin(i) * sin(i))]) % MOD;
		}
		printf("%d\n", x[n]);
	}
	return 0;
}
