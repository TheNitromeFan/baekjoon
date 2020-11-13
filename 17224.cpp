#include <cstdio>

int main(){
	int n, lim, k;
	scanf("%d %d %d", &n, &lim, &k);
	int easy = 0, hard = 0;
	for(int i = 0; i < n; ++i){
		int sub1, sub2;
		scanf("%d %d", &sub1, &sub2);
		if(sub2 <= lim){
			++hard;
		}else if(sub1 <= lim){
			++easy;
		}
	}
	int ans = 0;
	if(hard >= k){
		ans += k * 140;
		k = 0;
	}else{
		ans += hard * 140;
		k -= hard;
	}
	if(easy >= k){
		ans += k * 100;
		k = 0;
	}else{
		ans += easy * 100;
		k -= easy;
	}
	printf("%d", ans);
	return 0;
}
