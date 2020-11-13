#include <cstdio>

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	int ans = 1, page = 0;
	for(int i = 0; i < n; ++i){
		int x;
		scanf("%d", &x);
		if(page + x <= k){
			page += x;
		}else{
			++ans;
			page = x;
		}
	}
	printf("%d", ans);
	return 0;
}
