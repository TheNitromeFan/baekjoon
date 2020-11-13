#include <cstdio>

static bool is_not_prime[10000000];

void filter(){
	is_not_prime[0] = true;
	is_not_prime[1] = true;
	for(int m = 2; m * 2 < 10000000; ++m){
		is_not_prime[m * 2] = true;
	}
	for(int p = 3; p * p < 10000000; p += 2){
		for(int m = p; m * p < 10000000; m += 2){
			is_not_prime[m * p] = true;
		}
	}
}

int main(){
	filter();
	int k;
	scanf("%d", &k);
	int cnt = 0;
	int i = 0;
	while(true){
		if(!is_not_prime[i]){
			++cnt;
			if(cnt == k){
				printf("%d", i);
				break;
			}
		}
		++i;
	}
	return 0;
}
