#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		int prev;
		scanf("%d", &prev);
		int import = 0;
		while(true){
			int cur;
			scanf("%d", &cur);
			if(cur == 0){
				break;
			}
			if(cur > 2 * prev){
				import += cur - 2 * prev;
			}
			prev = cur;
		}
		printf("%d\n", import);
	}
	return 0;
}
