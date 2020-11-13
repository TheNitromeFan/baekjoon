#include <cstdio>
#define MAX (100 + 1)

int main(){
	int n;
	scanf("%d", &n);
	int a[MAX];
	for(int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
	}
	int m;
	scanf("%d", &m);
	for(int j = 0; j < m; ++j){
		int sex, num;
		scanf("%d %d", &sex, &num);
		if(sex == 1){
			for(int i = num; i <= n; i += num){
				a[i] = 1 - a[i];
			}
		}else{
			int left = num, right = num;
			while(left >= 1 && right <= n && a[left] == a[right]){
				--left;
				++right;
			}
			for(int i = left + 1; i < right; ++i){
				a[i] = 1 - a[i];
			}
		}
	}
	for(int i = 1; i <= n; ++i){
		printf("%d ", a[i]);
		if(i % 20 == 0){
			printf("\n");
		}
	}
	return 0;
}
