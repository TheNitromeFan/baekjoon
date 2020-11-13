#include <cstdio>
#include <algorithm>

int main(){
	int m, n;
	scanf("%d %d", &m, &n);
	printf("%d", std::min(2 * m - 2, 2 * n - 1));
	return 0;
}
