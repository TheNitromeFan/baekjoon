#include <cstdio>
#include <algorithm>

using std::max;
using std::min;

int main(){
	int rh, rv, sh, sv;
	scanf("%d %d %d %d", &rh, &rv, &sh, &sv);
	int n;
	scanf("%d", &n);
	int rhi, rvi, shi, svi, pi;
	scanf("%d %d %d %d %d", &rhi, &rvi, &shi, &svi, &pi);
	int p = min(
		max((rh - 1) / rhi + 1, (sh - 1) / shi + 1)
		* max((rv - 1) / rvi + 1, (sv - 1) / svi + 1),
		max((rh - 1) / rvi + 1, (sh - 1) / svi + 1)
		* max((rv - 1) / rhi + 1, (sv - 1) / shi + 1)
		) * pi;
	for(int i = 1; i < n; ++i){
		scanf("%d %d %d %d %d", &rhi, &rvi, &shi, &svi, &pi);
		p = min(p,
			min(
			max((rh - 1) / rhi + 1, (sh - 1) / shi + 1)
			* max((rv - 1) / rvi + 1, (sv - 1) / svi + 1),
			max((rh - 1) / rvi + 1, (sh - 1) / svi + 1)
			* max((rv - 1) / rhi + 1, (sv - 1) / shi + 1)
			) * pi);
	}
	printf("%d", p);
	return 0;
}
