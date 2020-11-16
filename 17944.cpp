#include <cstdio>

int main(){
	int n, t;
	scanf("%d %d", &n, &t);
	t = (t - 1) % (4 * n - 2) + 1;
	if(t <= 2 * n){
		printf("%d", t);
	}else{
		printf("%d", 4 * n - t);
	}
	return 0;
}
