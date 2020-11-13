#include <cstdio>
#include <cstdlib>
#include <algorithm>

using std::min;

int main(){
	int a, b, x, y;
	scanf("%d %d %d %d", &a, &b, &x, &y);
	printf("%d", min(min(abs(x - a) + abs(b - y), abs(y - a) + abs(b - x)), abs(b - a)));
	return 0;
}
