#include <cstdio>

int gcd(int a, int b){
	if(b == 0){
		return a;
	}else{
		return gcd(b, a % b);
	}
}

bool percentages(long long n, int pd, int pg){
	if(pg == 100){
		return pd == 100;
	}else if(pg == 0){
		return pd == 0;
	}
	int gcd1 = gcd(pd, 100);
	return 100 / gcd1 <= n;
}

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 1; a0 <= t; ++a0){
		long long n;
		int pd, pg;
		scanf("%lld %d %d", &n, &pd, &pg);
		printf("Case #%d: ", a0);
		if(percentages(n, pd, pg)){
			printf("Possible\n");
		}else{
			printf("Broken\n");
		}
	}
	return 0;
}
