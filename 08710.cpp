#include <cstdio>

int main(){
	int k, w, m;
	scanf("%d %d %d", &k, &w, &m);
	int bumps = 0;
	if(k < w){
		bumps = (w - k - 1) / m + 1;
	}
	printf("%d", bumps);
	return 0;
}
