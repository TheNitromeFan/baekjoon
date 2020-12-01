#include <cstdio>
#include <cstdlib>
#include <algorithm>

using std::sort;

int main(){
	int n;
	scanf("%d", &n);
	int x[100000], y[100000];
	for(int i = 0; i < n; ++i){
		scanf("%d %d", &x[i], &y[i]);
	}
	sort(x, x + n);
	sort(y, y + n);
	int cx = x[n / 2], cy = y[n / 2];
	long long dist = 0;
	for(int i = 0; i < n; ++i){
		dist += abs(x[i] - cx) + abs(y[i] - cy);
	}
	printf("%lld", dist);
	return 0;
}
