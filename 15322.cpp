#include <cstdio>
#include <algorithm>

int main(){
	int k;
	scanf("%d", &k);
	for(int i = 0; i < k; ++i){
		int n, m;
		scanf("%d %d", &n, &m);
		printf("%d\n", 2 * (std::min(n, m) - 1));
	}
	return 0;
}
