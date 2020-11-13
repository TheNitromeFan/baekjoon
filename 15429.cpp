#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	for(int a0 = 0; a0 < n; ++a0){
		int g;
		scanf("%d", &g);
		int moles[1001] = {};
		for(int i = 1; i <= g; ++i){
			scanf("%d", &moles[i]);
		}
		for(int i = 1; i + 2 <= g; ++i){
			if(moles[i] + 1 == moles[i + 2]){
				printf("%d\n", i + 1);
				break;
			}
		}
	}
	return 0;
}
