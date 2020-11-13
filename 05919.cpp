#include <cstdio>
#include <cstdlib>

int main(){
	int n;
	scanf("%d", &n);
	int a[10000];
	int sum = 0;
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
		sum += a[i];
	}
	int avg = sum / n;
	int var = 0;
	for(int i = 0; i < n; ++i){
		var += abs(avg - a[i]);
	}
	printf("%d", var / 2);
	return 0;
}
