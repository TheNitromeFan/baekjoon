#include <cstdio>

int records(int a[100000], int n, long long sz){
	int ret = 0;
	long long space = 0;
	for(int i = 0; i < n; ++i){
		if(space + a[i] <= sz){
			space += a[i];
		}else{
			++ret;
			space = a[i];
		}
	}
	++ret;
	return ret;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int rec[100000];
	long long max = 0, sum = 0;
	for(int i = 0; i < n; ++i){
		scanf("%d", &rec[i]);
		if(max < rec[i]){
			max = rec[i];
		}
		sum += rec[i];
	}
	long long low = max, high = sum;
	while(low < high){
		long long mid = (low + high) / 2;
		int x = records(rec, n, mid);
		if(x <= m){
			high = mid;
		}else{
			low = mid + 1;
		}
	}
	printf("%lld", high);
	return 0;
}
