#include <cstdio>

int main(){
	while(true){
		int n;
		scanf("%d", &n);
		if(n == 0){
			break;
		}
		long long marbles = 0, powOf2 = 1;
		for(int i = 1; i <= n; ++i){
			int mi;
			scanf("%d", &mi);
			marbles += mi * powOf2;
			powOf2 *= 2;
		}
		printf("%lld\n", marbles);
	}
	return 0;
}
