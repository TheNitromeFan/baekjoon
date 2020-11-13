#include <cstdio>
#include <algorithm>

int main(){
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	printf("%d", std::min(a + d, b + c));
	return 0;
}
