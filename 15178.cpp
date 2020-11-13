#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		printf("%d %d %d %s\n", a, b, c, (a + b + c == 180 ? "Seems OK" : "Check"));
	}
	return 0;
}
