#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int a[5000];
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	int ans = 1, dec = 0, inc = 0, s = 0;
	for(int i = 1; i < n; ++i){
		if(a[i-1] == a[i]){
			++dec;
			++inc;
		}else if(a[i-1] < a[i]){
			dec = 0;
			++inc;
		}else if(a[i-1] > a[i]){
			++dec;
			inc = 0;
		}
		if(inc >= 2 || dec >= 2){
			s = i-1;
		}
		if(i-s+1 > ans){
			ans = i-s+1;
		}
	}
	printf("%d", ans);
	return 0;
}
