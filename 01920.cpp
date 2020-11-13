#include <cstdio>
#include <algorithm>

bool search(int arr[100000], int start, int end, int target){
	if(start > end){
		return false;
	}
	int middle = (start + end) / 2;
	if(arr[middle] == target){
		return true;
	}else if(arr[middle] > target){
		return search(arr, start, middle-1, target);
	}else{
		return search(arr, middle+1, end, target);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	int a[100000];
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	std::sort(a, a+n);
	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; ++i){
		int x;
		scanf("%d", &x);
		printf("%d\n", search(a, 0, n-1, x));
	}
	return 0;
}
