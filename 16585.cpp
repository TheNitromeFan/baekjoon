#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int a[101];
	for(int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
	}
	int x1;
	char dir1[10];
	scanf("%d %s", &x1, dir1);
	int sum = 0;
	if(dir1[0] == 'l'){
		for(int i = x1; i >= 1; --i){
			sum += a[i];
		}
	}else{
		for(int i = x1; i <= n; ++i){
			sum += a[i];
		}
	}
	printf("%d ", sum);
	int x2;
	char dir2[10];
	scanf("%d %s", &x2, dir2);
	int cnt = 0;
	if(dir2[0] == 'l'){
		for(int i = x2; i >= 1; --i){
			if(a[i] == 0){
				++cnt;
			}
		}
	}else{
		for(int i = x2; i <= n; ++i){
			if(a[i] == 0){
				++cnt;
			}
		}
	}
	printf("%d", cnt);
	return 0;
}
