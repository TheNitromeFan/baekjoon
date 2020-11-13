#include <cstdio>
#include <algorithm>

using std::max;

int main(){
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	printf("%d", max(max(a + b, b + c), c + a));
	return 0;
}
