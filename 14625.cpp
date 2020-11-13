#include <cstdio>

bool appears(int n, int digit){
	for(int i = 0; i < 4; ++i){
		if(n % 10 == digit){
			return true;
		}
		n /= 10;
	}
	return false;
}

int main(){
	int h, m;
	scanf("%d %d", &h, &m);
	int start = 60 * h + m;
	scanf("%d %d", &h, &m);
	int end = 60 * h + m;
	int digit;
	scanf("%d", &digit);
	int ans = 0;
	for(int time = start; time <= end; ++time){
		int h = time / 60, m = time % 60;
		if(appears(100 * h + m, digit)){
			++ans;
		}
	}
	printf("%d", ans);
	return 0;
}
