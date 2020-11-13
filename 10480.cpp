#include <cstdio>
#include <cstdlib>

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		int x;
		scanf("%d", &x);
		printf("%d is %s\n", x, abs(x) % 2 ? "odd" : "even");
	}
	return 0;
}
