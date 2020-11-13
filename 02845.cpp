#include <cstdio>

int main(){
	int ell, p;
	scanf("%d %d", &ell, &p);
	for(int i = 0; i < 5; ++i){
		int x;
		scanf("%d", &x);
		printf("%d ", x - ell * p);
	}
	return 0;
}
