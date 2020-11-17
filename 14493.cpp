#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int a[50000], b[50000];
	for(int i = 0; i < n; ++i){
		scanf("%d %d", &a[i], &b[i]);
	}
	int time = 0;
	int idx = 0;
	while(idx < n){
		if(time % (a[idx] + b[idx]) < b[idx]){
			time += b[idx] - time % (a[idx] + b[idx]);
		}
		++time;
		++idx;
	}
	printf("%d", time);
	return 0;
}
