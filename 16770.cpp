#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int time[1001] = {};
	for(int i = 0; i < n; ++i){
		int si, ti, bi;
		scanf("%d %d %d", &si, &ti, &bi);
		time[si] = bi;
		time[ti] = -bi;
	}
	int maxBuckets = 0, buckets = 0;
	for(int j = 1; j <= 1000; ++j){
		buckets += time[j];
		if(maxBuckets < buckets){
			maxBuckets = buckets;
		}
	}
	printf("%d", maxBuckets);
	return 0;
}
