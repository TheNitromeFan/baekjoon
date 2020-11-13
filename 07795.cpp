#include <cstdio>
#include <algorithm>
#define MAX (20000 + 1)

using std::sort;

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		int n, m;
		scanf("%d %d", &n, &m);
		int a[MAX], b[MAX];
		for(int i = 1; i <= n; ++i){
			scanf("%d", &a[i]);
		}
		for(int j = 1; j <= m; ++j){
			scanf("%d", &b[j]);
		}
		sort(a + 1, a + n + 1);
		sort(b + 1, b + m + 1);
		int ans = 0;
		int j = 1;
		for(int i = 1; i <= n; ++i){
			while(j <= m && b[j] < a[i]){
				++j;
			}
			ans += j - 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}
