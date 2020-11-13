#include <cstdio>

int main(){
	int pyramids[201];
	for(int i = 0; i <= 200; ++i){
		pyramids[i] = i * (i + 1) / 2 * (i + 2) / 3;
	}
	int a[300001] = {};
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		for(int j = 1; pyramids[j] <= i; ++j){
			if(a[i] == 0 || a[i - pyramids[j]] + 1 < a[i]){
				a[i] = a[i - pyramids[j]] + 1;
			}
		}
	}
	printf("%d", a[n]);
	return 0;
}
