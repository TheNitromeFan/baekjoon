#include <cstdio>

bool all_seen(bool x[10]){
	for(int i = 0; i < 10; ++i){
		if(!x[i]){
			return false;
		}
	}
	return true;
}

void digit_see(bool digits[10], int n){
	while(n){
		digits[n % 10] = true;
		n /= 10;
	}
}

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; ++i){
		int n;
		scanf("%d", &n);
		printf("Case #%d: ", i);
		if(n == 0){
			printf("INSOMNIA\n");
			continue;
		}
		int ans = 0;
		bool seen[10] = {};
		while(!all_seen(seen)){
			++ans;
			digit_see(seen, n * ans);
		}
		printf("%d\n", n * ans);
	}
	return 0;
}
