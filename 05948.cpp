#include <cstdio>

int randomCount(int n){
	bool a[10000] = {};
	a[n] = true;
	int cnt = 1;
	while(true){
		int m = n / 10 % 100;
		n = m * m;
		if(a[n]){
			return cnt;
		}
		a[n] = true;
		++cnt;
	}
}

int main(){
	int n;
	scanf("%d", &n);
	printf("%d", randomCount(n));
	return 0;
}
