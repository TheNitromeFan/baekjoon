#include <cstdio>
#include <cstdlib>

int main(){
	int n;
	scanf("%d", &n);
	int a[20000];
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	int idx = 0, min_diff = 2000000000;
	for(int i = 0; i < n; ++i){
		int sum = 0;
		for(int j = 0; j < n; ++j){
			sum += abs(a[i] - a[j]);
		}
		if(sum < min_diff || (sum == min_diff && a[idx] > a[i])){
			min_diff = sum;
			idx = i;
		}
	}
	printf("%d", a[idx]);
	return 0;
}
