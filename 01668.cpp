#include <cstdio>
#define MAX 50

int main(){
	int n;
	scanf("%d", &n);
	int a[MAX];
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	int max, ans;
	ans = 0;
	max = 0;
	for(int i = 0; i < n; ++i){
		if(max < a[i]){
			max = a[i];
			++ans;
		}
	}
	printf("%d\n", ans);
	ans = 0;
	max = 0;
	for(int i = n - 1; i >= 0; --i){
		if(max < a[i]){
			max = a[i];
			++ans;
		}
	}
	printf("%d\n", ans);
	return 0;
}
