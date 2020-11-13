#include <cstdio>

int main(){
	int n, q;
	scanf("%d %d", &n, &q);
	bool spots[10001] = {};
	for(int i = 0; i < q; ++i){
		int ell, eye;
		scanf("%d %d", &ell, &eye);
		for(int j = ell; j <= n; j += eye){
			spots[j] = true;
		}
	}
	int ans = 0;
	for(int j = 1; j <= n; ++j){
		if(!spots[j]){
			++ans;
		}
	}
	printf("%d", ans);
	return 0;
}
