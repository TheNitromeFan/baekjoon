#include <cstdio>

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int a, b;
	scanf("%d %d", &a, &b);
	bool flipped = false;
	for(int i = 0; i < m; ++i){
		int k;
		scanf("%d", &k);
		if(flipped && b <= k){
			flipped = false;
		}else if(!flipped && a <= k){
			flipped = true;
		}
	}
	printf("%d", flipped ? b : a);
	return 0;
}
