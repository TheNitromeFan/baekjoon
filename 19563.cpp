#include <cstdio>
#include <cstdlib>

int main(){
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	printf("%s", (abs(a) + abs(b) <= c && (c - abs(a) - abs(b)) % 2 == 0) ? "YES" : "NO");
	return 0;
}
