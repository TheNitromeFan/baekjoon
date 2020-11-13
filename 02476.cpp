#include <cstdio>


int max(int a, int b){
	
	if(a > b) return a;
	else return b;
}

int score(int a, int b, int c){
	
	if(a == b && b == c) return 10000 + a * 1000;
	else if(a == b || a == c) return 1000 + a * 100;
	else if(b == c) return 1000 + b * 100;
	else return max(max(a, b), c) * 100;
}

int main(void){
	
	int n;
	scanf("%d", &n);
	int maximum = 0;
	for(int i = 0; i < n; i++){
		int d1, d2, d3;
		scanf("%d %d %d", &d1, &d2, &d3);
		maximum = max(maximum, score(d1, d2, d3));
	}
	printf("%d", maximum);
	return 0;
}
