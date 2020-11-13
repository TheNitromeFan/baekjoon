#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int ans = 0;
	for(int a = 1; a <= 500; ++a){
		for(int b = 1; b <= a; ++b){
			if(a * a - b * b == n){
				++ans;
			}
		}
	}
	printf("%d", ans);
	return 0;
}
