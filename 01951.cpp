#include <cstdio>
#define MOD 1234567

int ten_powers[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

int main(){
	int n;
	scanf("%d", &n);
	int ans = 0;
	int i;
	for(i = 0; i < 9; ++i){
		if(n / 10 < ten_powers[i]){
			break;
		}
		ans = (ans + (i + 1) * ((ten_powers[i + 1] - ten_powers[i]) % MOD)) % MOD;
	}
	ans = (ans + (i + 1) * ((n - ten_powers[i] + 1) % MOD)) % MOD;
	printf("%d", ans);
	return 0;
}
