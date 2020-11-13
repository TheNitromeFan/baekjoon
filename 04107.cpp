#include <cstdio>

int main(){
	while(true){
		int n, m, k;
		scanf("%d %d %d", &n, &m, &k);
		if(n == 0 && m == 0 && k == 0){
			break;
		}
		int pattern[100] = {};
		for(int i = 0; i < k; ++i){
			scanf("%d", &pattern[i]);
		}
		int stitches = 0;
		for(int row = 0; row < m; ++row){
			stitches += n;
			n += pattern[row % k];
		}
		printf("%d\n", stitches);
	}
	return 0;
}
