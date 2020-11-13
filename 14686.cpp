#include <cstdio>
#define MAX (100000 + 1)

int main(){
	int n;
	scanf("%d", &n);
	int sw[MAX], se[MAX];
	for(int i = 1; i <= n; ++i){
		scanf("%d", &sw[i]);
	}
	for(int i = 1; i <= n; ++i){
		scanf("%d", &se[i]);
	}
	int k = 0;
	long long sum_sw = 0, sum_se = 0;
	for(int i = 1; i <= n; ++i){
		sum_sw += sw[i];
		sum_se += se[i];
		if(sum_sw == sum_se){
			k = i;
		}
	}
	printf("%d", k);
	return 0;
}
