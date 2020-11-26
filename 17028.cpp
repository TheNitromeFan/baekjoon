#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int a[100];
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	int idx = n - 1;
	while(idx >= 1){
		if(a[idx - 1] > a[idx]){
			break;
		}
		--idx;
	}
	printf("%d", idx);
	return 0;
}
