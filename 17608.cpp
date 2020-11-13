#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	static int a[100000];
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	int ans = 0, max = 0;
	for(int i = n - 1; i >= 0; --i){
		if(a[i] > max){
			++ans;
			max = a[i];
		}
	}
	printf("%d", ans);
	return 0;
}
