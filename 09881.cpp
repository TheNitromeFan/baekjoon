#include <cstdio>
#include <limits>

int main(){
	int n;
	scanf("%d", &n);
	int a[1000];
	int low = 101, high = -1;
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
		if(a[i] < low){
			low = a[i];
		}
		if(a[i] > high){
			high = a[i];
		}
	}
	// printf("%d %d\n", low, high);
	int minSum = std::numeric_limits<int>::max();
	for(int x = low, y = low + 17; y <= high; ++x, ++y){
		int sum = 0;
		for(int i = 0; i < n; ++i){
			if(a[i] < x){
				sum += (x - a[i]) * (x - a[i]);
			}
			if(a[i] > y){
				sum += (a[i] - y) * (a[i] - y);
			}
		}
		if(minSum > sum){
			minSum = sum;
		}
	}
	printf("%d", minSum);
	return 0;
}
