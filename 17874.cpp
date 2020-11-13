#include <cstdio>
#include <algorithm>

using std::max;

int main(){
	int n, h, v;
	scanf("%d %d %d", &n, &h, &v);
	printf("%d", max(h, n - h) * max(v, n - v) * 4);
	return 0;
}
