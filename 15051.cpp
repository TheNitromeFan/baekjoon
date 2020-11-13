#include <cstdio>
#include <algorithm>

using std::min;

int main(){
	int a1, a2, a3;
	scanf("%d %d %d", &a1, &a2, &a3);
	printf("%d", 2 * min(min(2 * a1 + a2, 2 * a3 + a2), a1 + a3));
	return 0;
}
