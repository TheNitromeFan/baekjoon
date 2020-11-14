#include <cstdio>

bool check(int a[1001], int b[1000], int n, int a1){
	bool used[1001] = {};
	a[1] = a1;
	used[a[1]] = true;
	for(int i = 2; i <= n; ++i){
		a[i] = b[i - 1] - a[i - 1];
		if(a[i] < 1 || a[i] > n || used[a[i]]){
			return false;
		}
		used[a[i]] = true;
	}
	return true;
}

int main(){
	int n;
	scanf("%d", &n);
	int b[1000];
	for(int i = 1; i < n; ++i){
		scanf("%d", &b[i]);
	}
	int a[1001];
	for(int a1 = 1; a1 <= n; ++a1){
		if(check(a, b, n, a1)){
			break;
		}
	}
	for(int i = 1; i <= n; ++i){
		printf("%d ", a[i]);
	}
	return 0;
}
