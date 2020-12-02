#include <cstdio>
#include <cstring>

inline int next(int x, int n){
	return (x + 1) % n;
}

inline int prev(int x, int n){
	return (x + n - 1) % n;
}

long long ioi(long long dp[][2001], long long a[2001], int n, int left, int right);
long long joi(long long dp[][2001], long long a[2001], int n, int left, int right);

long long ioi(long long dp[][2001], long long a[2001], int n, int left, int right){
	if(next(right, n) == left){
		return 0;
	}
	if(a[prev(left, n)] < a[next(right, n)]){
		return joi(dp, a, n, left, next(right, n));
	}else{
		return joi(dp, a, n, prev(left, n), right);
	}
}

long long joi(long long dp[][2001], long long a[2001], int n, int left, int right){
	if(next(right, n) == left){
		return 0;
	}
	if(dp[left][right] != -1){
		return dp[left][right];
	}
	long long ret1 = a[prev(left, n)] + ioi(dp, a, n, prev(left, n), right);
	long long ret2 = a[next(right, n)] + ioi(dp, a, n, left, next(right, n));
	dp[left][right] = (ret1 > ret2) ? ret1 : ret2;
	return dp[left][right];
}

int main(){
	int n;
	scanf("%d", &n);
	long long a[2001];
	for(int i = 0; i < n; ++i){
		scanf("%lld", &a[i]);
	}
	long long dp[2001][2001];
	memset(dp, -1, sizeof(dp));
	long long ans = 0;
	for(int i = 0; i < n; ++i){
		long long cmp = a[i] + ioi(dp, a, n, i, i);
		if(ans < cmp){
			ans = cmp;
		}
	}
	printf("%lld", ans);
	return 0;
}
