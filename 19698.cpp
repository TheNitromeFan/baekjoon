#include <cstdio>
#include <algorithm>

using std::min;

int main(){
	int n, w, h, ell;
	scanf("%d %d %d %d", &n, &w, &h, &ell);
	printf("%d", min(n, (w / ell) * (h / ell)));
	return 0;
}
