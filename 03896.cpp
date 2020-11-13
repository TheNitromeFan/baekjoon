#include <cstdio>
#include <cstring>
#define MAX (1299709 + 1)

static bool prime[MAX];

void preprocess(){
	memset(prime, true, sizeof(prime));
	prime[0] = false;
	prime[1] = false;
	for(int p = 2; p * p < MAX; ++p){
		if(!prime[p]){
			continue;
		}
		for(int m = p; m * p < MAX; ++m){
			prime[m * p] = false;
		}
	}
}

int main(){
	preprocess();
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		int x;
		scanf("%d", &x);
		if(prime[x]){
			printf("0\n");
			continue;
		}
		int low = x, high = x;
		while(!prime[low]){
			--low;
		}while(!prime[high]){
			++high;
		}
		printf("%d\n", high - low);
	}
	return 0;
}
