#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int cnt = 0;
	for(int i = 0; i < (1 << (n - 1)); ++i){
		int left = 0, right = 0;
		int k = i;
		for(int j = 1; j < n; ++j){
			if(k % 2 == 0){
				left += j;
			}else{
				right += j;
			}
			k /= 2;
		}
		if(left + n == right){
			++cnt;
		}
	}
	printf("%d", cnt);
	return 0;
}
