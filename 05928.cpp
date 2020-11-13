#include <cstdio>

int main(){
	int d, h, m;
	scanf("%d %d %d", &d, &h, &m);
	int ans = (d - 11) * 60 * 24 + (h - 11) * 60 + m - 11;
	printf("%d", ans >= 0 ? ans : -1);
	return 0;
}
