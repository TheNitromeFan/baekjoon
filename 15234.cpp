#include <cstdio>
#define MAX 1000

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	int a[MAX];
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	int ans = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < i; ++j){
			if(a[i] + a[j] == k){
				++ans;
			}
		}
	}
	printf("%d", ans);
	return 0;
}
