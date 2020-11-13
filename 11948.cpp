#include <cstdio>
#include <algorithm>

using std::min;

int main(){
	int a, b, c, d, e, f;
	scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
	printf("%d", a + b + c + d + e + f - min(min(a, b), min(c, d)) - min(e, f));
	return 0;
}
