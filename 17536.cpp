#include <cstdio>
#include <cmath>

int main(){
	int v, n;
	scanf("%d %d", &v, &n);
	for(int i = 1; i < 10; ++i){
		double mark = v * n / 10.0 * i;
		printf("%d ", (int)ceil(mark));
	}
	return 0;
}
