#include <cstdio>

int main(){
	int k;
	scanf("%d", &k);
	int app = 1;
	for(int i = 0; i < k; ++i){
		int o;
		scanf("%d", &o);
		app += (o - 1);
	}
	printf("%d", app);
	return 0;
}
