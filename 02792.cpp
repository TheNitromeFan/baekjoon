#include <cstdio>

int groups(int k[300000], int n, int envy){
	int ret = 0;
	for(int i = 0; i < n; ++i){
		ret += (k[i] - 1) / envy + 1;
	}
	return ret;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int k[300000];
	for(int i = 0; i < m; ++i){
		scanf("%d", &k[i]);
	}
	int low = 1, high = 1000000000;
	while(low < high){
		int mid = (low + high) / 2;
		int g = groups(k, m, mid);
		if(g <= n){
			high = mid;
		}else{
			low = mid + 1;
		}
	}
	printf("%d", high);
	return 0;
}
