#include <cstdio>
#include <algorithm>

using std::sort;

int waits(int d[10001], int n){
	if(n % 2 == 1){
		return 1;
	}
	sort(d + 1, d + n + 1);
	return d[n / 2 + 1] - d[n / 2] + 1;
}

int main(){
	int n;
	scanf("%d", &n);
	int d[10001] = {};
	for(int i = 1; i <= n; ++i){
		int s, a;
		scanf("%d %d", &s, &a);
		d[i] = s - a;
	}
	printf("%d", waits(d, n));
	return 0;
}
