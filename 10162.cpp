#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	if(t % 10 != 0){
		printf("-1");
		return 0;
	}
	int a = t / 300;
	t %= 300;
	int b = t / 60;
	t %= 60;
	int c = t / 10;
	printf("%d %d %d", a, b, c);
	return 0;
}
