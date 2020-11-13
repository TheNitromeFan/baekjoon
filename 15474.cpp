#include <cstdio>
#include <algorithm>

using std::min;

int main(){
	int n, a, b, c, d;
	scanf("%d %d %d %d %d", &n, &a, &b, &c, &d);
	int x = (n - 1) / a + 1, y = (n - 1) / c + 1;
	printf("%d", min(x * b, y * d));
	return 0;
}
