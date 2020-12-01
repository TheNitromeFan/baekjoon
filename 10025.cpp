#include <cstdio>

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	static long long grass[1000002] = {};
	for(int i = 0; i < n; ++i){
		long long gi;
		int xi;
		scanf("%lld %d", &gi, &xi);
		grass[xi] = gi;
	}
	static long long psum[1000002] = {};
	psum[0] = grass[0];
	for(int j = 1; j <= 1000000; ++j){
		psum[j] = psum[j - 1] + grass[j];
	}
	if(k > 1000000){
		printf("%lld", psum[1000000]);
		return 0;
	}
	long long ans = 0;
	for(int i = 0; i <= 1000000; ++i){
		if(i + k <= 1000000 && i - k >= 1 && ans < psum[i + k] - psum[i - k - 1]){
			ans = psum[i + k] - psum[i - k - 1];
		}
	}
	printf("%lld", ans);
	return 0;
}
