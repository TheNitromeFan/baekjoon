#include <cstdio>

int contains_369(int n){
	int ret = 0;
	while(n){
		switch(n % 10){
			case 3:
			case 6:
			case 9:
				++ret;
				break;
		}
		n /= 10;
	}
	return ret;
}

int main(){
	int n;
	scanf("%d", &n);
	int ans = 0;
	for(int i = 1; i <= n; ++i){
		ans += contains_369(i);
	}
	printf("%d", ans);
	return 0;
}
