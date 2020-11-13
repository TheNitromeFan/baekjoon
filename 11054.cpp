#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int a[1000];
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	int lis[1000], lds[1000];
	for(int i = 0; i < n; ++i){
		lis[i] = 1;
		lds[i] = 1;
	}
	for(int i = 1; i < n; ++i){
		for(int j = 0; j < i; ++j){
			if(a[i] > a[j] && lis[i] < lis[j] + 1){
				lis[i] = lis[j] + 1;
			}
		}
	}
	for(int i = n-2; i >= 0; --i){
		for(int j = n-1; j > i; --j){
			if(a[i] > a[j] && lds[i] < lds[j] + 1){
				lds[i] = lds[j] + 1;
			}
		}
	}
	int len = lis[0] + lds[0] - 1;
	for(int i = 1; i < n; ++i){
		if(lis[i] + lds[i] - 1 > len){
			len = lis[i] + lds[i] - 1;
		}
	}
	printf("%d", len);
	return 0;
}
