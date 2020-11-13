#include <cstdio>
#include <algorithm>

long long expense(int a[10000], int size, int limit){
	long long sum = 0;
	for(int i = 0; i < size; ++i){
		sum += std::min(a[i], limit);
	}
	return sum;
}

int main(){
	int n;
	scanf("%d", &n);
	int a[10000];
	int biggest = 0;
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
		if(a[i] > biggest){
			biggest = a[i];
		}
	}
	int budget;
	scanf("%d", &budget);
	int low = 0, high = biggest;
	int ans = 0;
	while(low <= high){
		int mid = (low + high) / 2;
		if(expense(a, n, mid) <= budget){
			ans = mid;
			low = mid + 1;
		}else{
			high = mid - 1;
		}
	}
	printf("%d", ans);
	return 0;
}
