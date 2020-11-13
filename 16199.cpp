#include <cstdio>

int main(){
	int by, bm, bd, ny, nm, nd;
	scanf("%d %d %d\n%d %d %d", &by, &bm, &bd, &ny, &nm, &nd);
	int ans;
	ans = ny - by;
	if(nm < bm || (nm == bm && nd < bd)){
		--ans;
	}
	printf("%d\n", ans);
	printf("%d\n%d", ny - by + 1, ny - by);
	return 0;
}
