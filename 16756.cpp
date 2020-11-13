#include <cstdio>
#include <cstdlib>
#define MAX 100000

int main(){
	int n;
	scanf("%d", &n);
	int a[MAX];
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	int ans = 2000000001;
	for(int i = 0; i < n - 1; ++i){
		if(ans > abs(a[i + 1] - a[i])){
			ans = abs(a[i + 1] - a[i]);
		}
	}
	printf("%d", ans);
	return 0;
}
