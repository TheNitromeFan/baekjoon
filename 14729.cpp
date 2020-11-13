#include <cstdio>
#define MAX (100000 + 1)

void print(int cnt[MAX]){
	int s = 0;
	for(int j = 0; j <= MAX; ++j){
		for(int k = 0; k < cnt[j]; ++k){
			printf("%.3f\n", j / 1000.0);
			++s;
			if(s == 7){
				return;
			}
		}
	}
}

int main(){
	int n;
	scanf("%d", &n);
	int cnt[MAX] = {};
	for(int i = 0; i < n; ++i){
		double x;
		scanf("%lf", &x);
		++cnt[(int)(x * 1000)];
	}
	print(cnt);
	return 0;
}
