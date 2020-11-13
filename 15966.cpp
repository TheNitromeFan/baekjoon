#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int a[100000];
	int max = 1, cnt, cur;
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
		cur = a[i];
		cnt = 1;
		for(int j = i-1; j >= 0; --j){
			if(a[j] == cur - 1){
				cur -= 1;
				++cnt;
			}
		}
		if(cnt > max){
			max = cnt;
		}
	}
	printf("%d", max);
	return 0;
}
