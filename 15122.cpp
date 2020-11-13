#include <cstdio>

bool has_zero(int n){
	while(n){
		if(n % 10 == 0){
			return true;
		}
		n /= 10;
	}
	return false;
}

int main(){
	int n;
	scanf("%d", &n);
	int ans = n + 1;
	while(has_zero(ans)){
		++ans;
	}
	printf("%d", ans);
	return 0;
}
