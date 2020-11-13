#include <cstdio>

int main(){
	while(true){
		int a;
		scanf("%d", &a);
		if(a == 0){
			break;
		}
		int leaves = 1;
		for(int i = 0; i < a; ++i){
			int split, prune;
			scanf("%d %d", &split, &prune);
			leaves *= split;
			leaves -= prune;
		}
		printf("%d\n", leaves);
	}
	return 0;
}
