#include <cstdio>

int main(){
	int n, w, h;
	scanf("%d %d %d", &n, &w, &h);
	for(int i = 0; i < n; ++i){
		int x;
		scanf("%d", &x);
		printf("%s\n", x * x <= w * w + h * h ? "YES" : "NO");
	}
	return 0;
}
