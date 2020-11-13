#include <cstdio>
#include <algorithm>

using std::min;

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 1; a0 <= t; ++a0){
		int n;
		scanf("%d", &n);
		double b[1001] = {};
		for(int i = 1; i <= n; ++i){
			scanf("%lf", &b[i]);
		}
		for(int i = 2; i <= n - 1; ++i){
			b[i] = min(b[i], (b[i - 1] + b[i + 1]) / 2);
		}
		printf("Case #%d: %.6lf\n", a0, b[n - 1]);
	}
	return 0;
}
