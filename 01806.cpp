#include <cstdio>
#define MAX 100000

int main(){
	int n, s;
	scanf("%d %d", &n, &s);
	int a[MAX + 1] = {};
	int running_sum = 0;
	int len = 2*n + 1;
	int j = 1;
	for(int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
		running_sum += a[i];
		while(j < i && running_sum - a[j] >= s){
			running_sum -= a[j];
			++j;
		}
		if(running_sum >= s && len > i - j + 1){
			len = i - j + 1;
		}
	}
	printf("%d", (len == 2*n + 1 ? 0 : len));
	return 0;
}
