#include <cstdio>

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int a[100001], b[100001];
	int maxA = 0;
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
		if(maxA < a[i]){
			maxA = a[i];
		}
	}
	int maxB = 0;
	for(int j = 0; j < m; ++j){
		scanf("%d", &b[j]);
		if(maxB < b[j]){
			maxB = b[j];
		}
	}
	long long score = 0;
	int i, j;
	for(i = 0; a[i] < maxA; ++i){
		score += (long long)a[i] * 1000000000 + b[0];
	}
	for(j = 0; b[j] < maxB; ++j){
		score += (long long)a[i] * 1000000000 + b[j];
	}
	int k, l;
	for(k = n - 1; a[k] < maxA; --k){
		score += (long long)a[k] * 1000000000 + b[m - 1];
	}
	for(l = m - 1; b[l] < maxB; --l){
		score += (long long)a[k] * 1000000000 + b[l];
	}
	int x, y;
	for(x = i; x < k; ++x){
		score += (long long)a[x] * 1000000000 + b[j];
	}
	for(y = j; y < l; ++y){
		score += (long long)a[k] * 1000000000 + b[y];
	}
	score += (long long)a[k] * 1000000000 + b[l];
	printf("%lld", score);
	return 0;
}
