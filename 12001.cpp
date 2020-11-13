#include<stdio.h>

struct xy { int x, y; }a[121];

int sb(xy a, xy b) { return (a.x < b.x) * 2 + (a.y < b.y); }

int main() {
	int n, b,i, j, k, ans = 1e9;
	scanf("%d%d", &n,&b);
	for (i = 0; i < n; i++)scanf("%d%d", &a[i].x, &a[i].y);
	for (i = 0; i < n; i++) for (k = 0; k < n; k++){
		int cnt[4] = { 0, }, res = 0;
		for (j = 0; j < n; j++) cnt[sb({ a[i].x + 1,a[k].y + 1 }, a[j])]++;
		for (j = 0; j < 4; j++)if (res < cnt[j])res = cnt[j];
		if (ans > res)ans = res;
	}
	printf("%d", ans);
	return 0;
}
