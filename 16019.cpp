#include <cstdio>
#include <cstdlib>

int main(){
	int pos[5] = {};
	for(int i = 1; i < 5; ++i){
		int x;
		scanf("%d", &x);
		pos[i] = pos[i - 1] + x;
	}
	for(int i = 0; i < 5; ++i){
		for(int j = 0; j < 5; ++j){
			printf("%d ", abs(pos[i] - pos[j]));
		}
		printf("\n");
	}
	return 0;
}
