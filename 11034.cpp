#include <cstdio>
#include <algorithm>

int main(){
	int a, b, c;
	while(scanf("%d %d %d", &a, &b, &c) == 3){
		printf("%d\n", std::max(b - a, c - b) - 1);
	}
	return 0;
}
