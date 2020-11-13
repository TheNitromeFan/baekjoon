#include <cstdio>

int main(){
	int ah, am, as, bh, bm, bs;
	scanf("%d:%d:%d\n%d:%d:%d", &ah, &am, &as, &bh, &bm, &bs);
	int t = ((60 * 60 * bh + 60 * bm + bs) - (60 * 60 * ah + 60 * am + as) + 60 * 60 * 24) % (60 * 60 * 24);
	printf("%02d:%02d:%02d", t / 60 / 60, t / 60 % 60, t % 60);
	return 0;
}
