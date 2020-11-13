#include <cstdio>

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	printf("%s", m * n % 3 == 0 ? "YES" : "NO");
	return 0;
}
