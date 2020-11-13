#include <cstdio>

int main(){
	int n, c;
	scanf("%d %d", &n, &c);
	int m, s;
	scanf("%d:%d", &m, &s);
	int time = 60 * m + s;
	for(int i = 1; i < n; ++i){
		scanf("%d:%d", &m, &s);
		time += 60 * m + s - c;
	}
	printf("%02d:%02d:%02d", time / 60 / 60, time / 60 % 60, time % 60);
	return 0;
}
