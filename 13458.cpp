#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	static int a[1000000];
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	int b, c;
	scanf("%d %d", &b, &c);
	long long ans = n;
	for(int i = 0; i < n; ++i){
		if(a[i] <= b){
			continue;
		}
		ans += ((a[i] - b) % c == 0) ? (a[i] - b) / c : (a[i] - b) / c + 1;
	}
	printf("%lld", ans);
	return 0;
}
