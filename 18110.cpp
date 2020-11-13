#include <cstdio>
#include <cmath>
#include <algorithm>
#define MAX 300000

using std::sort;

int main(){
	int n;
	scanf("%d", &n);
	if(n == 0){
		printf("0");
		return 0;
	}
	int a[MAX];
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	int cutoff = (int)floor(n * 3 / 20.0 + 0.5);
	int sum = 0;
	for(int i = cutoff; i < n - cutoff; ++i){
		sum += a[i];
	}
	// printf("%d %d\n", cutoff, sum);
	printf("%d", (int)floor(sum / (double)(n - cutoff * 2) + 0.5));
	return 0;
}
