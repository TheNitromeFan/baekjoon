#include <cstdio>

int a[100001], copy[100001], result[100001];
int n;
long long t;

bool possible(int diff){
	for(int i = 0; i < n; ++i){
		copy[i] = a[i];
	}
	long long cnt = 0;
	for(int i = 0; i < n-1; ++i){
		if(copy[i+1] > copy[i] + diff){
			cnt += copy[i+1] - copy[i] - diff;
			copy[i+1] = copy[i] + diff;
		}
	}
	for(int i = n-1; i > 0; --i){
		if(copy[i-1] > copy[i] + diff){
			cnt += copy[i-1] - copy[i] - diff;
			copy[i-1] = copy[i] + diff;
		}
	}
	return cnt <= t;
}

int main(){
	scanf("%d %lld", &n, &t);
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	int low = 0, high = 1000000001;
	while(low <= high){
		int mid = (low + high) / 2;
		if(possible(mid)){
			for(int i = 0; i < n; ++i){
				result[i] = copy[i];
			}
			high = mid - 1;
		}else{
			low = mid + 1;
		}
	}
	for(int i = 0; i < n; ++i){
		printf("%d ", result[i]);
	}
	return 0;
}
