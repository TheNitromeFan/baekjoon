#include <cstdio>
#define MAX 100000

int main(){
	int n;
	scanf("%d", &n);
	long long a[MAX];
	long long sum = 0;
	for(int i = 0; i < n; ++i){
		scanf("%lld", &a[i]);
		sum += a[i];
	}
	long long last = sum / 2;
	int idx;
	for(idx = 0; idx < n; ++idx){
		if(a[idx] == last){
			break;
		}
	}
	for(int i = 0; i < n; ++i){
		if(i != idx){
			printf("%lld ", a[i]);
		}
	}
	printf("%lld", a[idx]);
	return 0;
}
