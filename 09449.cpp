#include <cstdio>

int main(){
	int W, H, w, h;
	scanf("%d %d %d %d", &W, &H, &w, &h);
	int n = ((W - w + 1) % (2 * w) == 0) ? (W - w + 1) / (2 * w) : (W - w + 1) / (2 * w) + 1;
	int m = ((H - h + 1) % (2 * h) == 0) ? (H - h + 1) / (2 * h) : (H - h + 1) / (2 * h) + 1;
	printf("%d", n * m);
	return 0;
}
