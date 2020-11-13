#include <cstdio>

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	int cnt = 0;
	for(int time = 0; time < (n + 1) * 60 * 60; ++time){
		int h = time / 60 / 60, m = time / 60 % 60, s = time % 60;
		if(h / 10 == k || h % 10 == k || m / 10 == k || m % 10 == k || s / 10 == k || s % 10 == k){
			++cnt;
		}
	}
	printf("%d", cnt);
	return 0;
}
