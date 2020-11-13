#include <cstdio>
#include <algorithm>

using std::max;

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int sum = 0, worst = 0;
	for(int i = 0; i < m; ++i){
		int ai, bi;
		scanf("%d %d", &ai, &bi);
		int x = max(n - ai, 0);
		sum += x;
		if(worst < x){
			worst = x;
		}
	}
	printf("%d", sum - worst);
	return 0;
}
