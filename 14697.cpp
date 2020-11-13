#include <cstdio>

int main(){
	int a, b, c, n;
	scanf("%d %d %d %d", &a, &b, &c, &n);
	bool beds[301] = {};
	beds[0] = true;
	for(int i = 1; i <= n; ++i){
		if(i >= a){
			beds[i] = beds[i] || beds[i - a];
		}
		if(i >= b){
			beds[i] = beds[i] || beds[i - b];
		}
		if(i >= c){
			beds[i] = beds[i] || beds[i - c];
		}
	}
	printf("%d", beds[n]);
	return 0;
}
