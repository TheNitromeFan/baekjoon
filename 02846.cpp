#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int a[1000];
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	int start = a[0], end = a[0], max_climb = 0;
	for(int i = 1; i < n; ++i){
		if(a[i] <= a[i - 1]){
			if(max_climb < end - start){
				max_climb = end - start;
			}
			start = a[i];
			end = a[i];
		}else if(a[i] > a[i - 1]){
			end = a[i];
		}
	}
	if(max_climb < end - start){
		max_climb = end - start;
	}
	printf("%d", max_climb);
	return 0;
}
