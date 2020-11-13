#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int ans = 0;
	for(int i = 0; i <= 99; ++i){
		for(int j = 0; j <= 99; ++j){
			if(i + j == n){
				++ans;
			}
		}
	}
	printf("%d", ans);
	return 0;
}
