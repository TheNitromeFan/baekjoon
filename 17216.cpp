#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int ans = 0;
	int a[1000], max[1000];
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
		max[i] = a[i];
		for(int j = 0; j < i; ++j){
			if(a[j] > a[i] && max[i] < max[j] + a[i]){
				max[i] = max[j] + a[i];
			}
		}
		if(ans < max[i]){
			ans = max[i];
		}
	}
	printf("%d", ans);
	return 0;
}
