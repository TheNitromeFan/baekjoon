#include <cstdio>

int gcd(int a, int b){
	if(b == 0){
		return a;
	}else{
		return gcd(b, a % b);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	for(int a = 0; a < n; ++a){
		int m;
		scanf("%d", &m);
		int numbers[100];
		for(int i = 0; i < m; ++i){
			scanf("%d", &numbers[i]);
		}
		long long answer = 0;
		for(int i = 0; i < m; ++i){
			for(int j = 0; j < i; ++j){
				answer += gcd(numbers[i], numbers[j]);
			}
		}
		printf("%lld\n", answer);
	}
	return 0;
}
