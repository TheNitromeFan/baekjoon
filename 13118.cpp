#include <cstdio>

int main(){
	int p[5];
	for(int i = 1; i <= 4; ++i){
		scanf("%d", &p[i]);
	}
	int x, y, r;
	scanf("%d %d %d", &x, &y, &r);
	int cand = 0;
	for(int i = 1; i <= 4; ++i){
		if(p[i] == x){
			cand = i;
		}
	}
	printf("%d", cand);
	return 0;
}
