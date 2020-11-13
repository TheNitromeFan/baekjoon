#include <cstdio>
#include <algorithm>

using std::min;

int main(){
	int n;
	scanf("%d", &n);
	int k; 
	scanf("%d", &k);
	for(int i = 0; i < k; ++i){
		int a, b;
		scanf("%d %d", &a, &b);
		int d = min(min(a, b), min(n+1-a, n+1-b));
		printf("%d\n", (d-1) % 3 + 1);
	}
	return 0;
}
