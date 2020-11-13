#include <cstdio>
#include <cstring>
#define MAX 1000000

void sieve(bool pr[MAX]){
	memset(pr, true, MAX * sizeof(bool));
	pr[0] = false;
	pr[1] = false;
	for(int p = 2; p * p < MAX; ++p){
		if(!pr[p]){
			continue;
		}
		for(int m = p; m * p < MAX; ++m){
			pr[m * p] = false;
		}
	}
}

int main(){
	bool prime[MAX];
	sieve(prime);
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		int n;
		scanf("%d", &n);
		if(n == 4){
			printf("1\n");
			continue;
		}
		int ans = 0;
		for(int i = 3, j = n - 3; i <= j; i += 2, j -= 2){
			if(prime[i] && prime[j]){
				++ans;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
