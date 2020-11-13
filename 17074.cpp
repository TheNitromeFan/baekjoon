#include <cstdio>
#define MAX 100000

int main(){
	int n;
	scanf("%d", &n);
	int a[MAX];
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	int cnt = 0, idx = 0;
	for(int i = 0; i < n - 1; ++i){
		if(a[i] > a[i + 1]){
			++cnt;
			idx = i;
		}
	}
	if(cnt >= 2){
		printf("0");
		return 0;
	}
	else if(cnt == 0){
		printf("%d", n);
		return 0;
	}
	int spike = 0;
	if(idx > 0 && a[idx - 1] > a[idx + 1]){
		++spike;
	}
	if(idx + 1 < n - 1 && a[idx + 2] < a[idx]){
		++spike;
	}
	printf("%d", 2 - spike);
	return 0;
}
