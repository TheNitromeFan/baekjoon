#include <cstdio>
#include <algorithm>

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	int low = 1, high = k;
	int ans = -1;
	while(low <= high){
		int mid = (low + high) / 2;
		int cnt = 0;
		for(int i = 1; i <= n; ++i){
			cnt += std::min(mid / i, n);
		}
		if(cnt >= k){
			ans = mid;
			high = mid - 1;
		}else{
			low = mid + 1;
		}
	}
	printf("%d", ans);
	return 0;
}
