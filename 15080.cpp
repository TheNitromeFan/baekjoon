#include <cstdio>

int main(){
	int h, m, s;
	scanf("%d : %d : %d", &h, &m, &s);
	int start = h * 60 * 60 + m * 60 + s;
	scanf("%d : %d : %d", &h, &m, &s);
	int end = h * 60 * 60 + m * 60 + s;
	printf("%d", (end - start + 24 * 60 * 60) % (24 * 60 * 60));
	return 0;
}
