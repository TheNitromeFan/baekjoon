#include <cstdio>

int main(){
	bool submitted[31] = {};
	for(int i = 0; i < 28; ++i){
		int n;
		scanf("%d", &n);
		submitted[n] = true;
	}
	for(int i = 1; i <= 30; ++i){
		if(!submitted[i]){
			printf("%d\n", i);
		}
	}
	return 0;
}
