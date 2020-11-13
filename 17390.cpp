#include <cstdio>
#include <algorithm>

int main(){
	int n, q;
	scanf("%d %d", &n, &q);
	static int a[300000];
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	std::sort(a, a+n);
	static int pre[300001] = {};
	pre[1] = a[0];
	for(int i = 2; i <= n; ++i){
		pre[i] = pre[i-1] + a[i-1];
	}
	for(int q0 = 0; q0 < q; ++q0){
		int sum = 0;
		int left, right;
		scanf("%d %d", &left, &right);
		printf("%d\n", pre[right] - pre[left-1]);
	}
	return 0;
}
