#include <cstdio>
#include <cmath>
#define MAX 10000

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	int a[MAX];
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	long double ans = MAX * MAX;
	for(int len = k; len <= n; ++len){
		for(int i = 0; i + len <= n; ++i){
			int running_sum = 0;
			for(int j = i; j < i + len; ++j){
				running_sum += a[j];
			}
			long double avg = running_sum / (long double)len;
			long double sum = 0;
			for(int j = i; j < i + len; ++j){
				sum += (a[j] - avg) * (a[j] - avg);
			}
			long double cmp = sqrt(sum / (long double)len);
			if(ans > cmp){
				ans = cmp;
			}
		}
	}
	printf("%.11Lf", ans);
	return 0;
}
