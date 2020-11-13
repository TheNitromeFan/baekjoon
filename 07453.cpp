#include <cstdio>
#include <algorithm>
#include <functional>

int main(){
	int n;
	scanf("%d", &n);
	int arr[4000][4];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < 4; ++j){
			scanf("%d", &arr[i][j]);
		}
	}
	static int ab[16000000], cd[16000000];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			ab[i * n + j] = arr[i][0] + arr[j][1];
			cd[i * n + j] = arr[i][2] + arr[j][3];
		}
	}
	std::sort(ab, ab + n * n);
	std::sort(cd, cd + n * n, std::greater<int>());
	int abi = 0, cdi = 0;
	long long ans = 0;
	while(abi < n * n && cdi < n * n){
		if(ab[abi] + cd[cdi] > 0){
			++cdi;
			continue;
		}else if(ab[abi] + cd[cdi] < 0){
			++abi;
			continue;
		}
		int abcnt = 0, cdcnt = 0;
		while(ab[abi] + cd[cdi] == 0 && abi < n * n){
			++abi;
			++abcnt;
		}
		while(ab[abi-1] + cd[cdi] == 0 && cdi < n * n){
			++cdi;
			++cdcnt;
		}
		ans += (long long)abcnt * cdcnt;
	}
	printf("%lld", ans);
	return 0;
}
