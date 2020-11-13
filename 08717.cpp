#include <cstdio>
#include <cstdlib>

int main(){
	int n;
	scanf("%d", &n);
	static int a[1000000];
	int sum = 0;
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
		sum += a[i];
	}
	int minDiff = 2000000000;
	int leftSum = 0;
	for(int i = 0; i < n - 1; ++i){
		leftSum += a[i];
		int rightSum = sum - leftSum;
		if(abs(leftSum - rightSum) < minDiff){
			minDiff = abs(leftSum - rightSum);
		}
	}
	printf("%d", minDiff);
	return 0;
}
