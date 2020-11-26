#include <cstdio>
#include <cstring>
#define MOD 1000000009

int mem[1001][1001];

int sums(int sum, int cnt){
	if(sum < 0 || cnt < 0){
		return 0;
	}else if(sum == 0){
		return 1;
	}
	if(mem[sum][cnt] != -1){
		return mem[sum][cnt];
	}
	mem[sum][cnt] = (sums(sum - 3, cnt - 1) + sums(sum - 2, cnt - 1)) % MOD
	 + sums(sum - 1, cnt - 1);
	mem[sum][cnt] %= MOD;
	return mem[sum][cnt];
}

int main(){
	memset(mem, -1, sizeof(mem));
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		int n, m;
		scanf("%d %d", &n, &m);
		printf("%d\n", sums(n, m));
	}
	return 0;
}
