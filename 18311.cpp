#include <cstdio>

int main(){
	int n;
	long long k;
	scanf("%d %lld", &n, &k);
	int d[100001];
	for(int i = 1; i <= n; ++i){
		scanf("%d", &d[i]);
	}
	int ind = 1;
	int dir = 1;
	while(k >= d[ind]){
		k -= d[ind];
		if(dir == 1){
			if(ind == n){
				dir = -1;
			}else{
				++ind;
			}
		}else{
			--ind;
		}
	}
	printf("%d", ind);
	return 0;
}
