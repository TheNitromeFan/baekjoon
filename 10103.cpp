#include <cstdio>


int antonia = 100, david = 100;

void score(int a, int d){
	
	if(a < d) antonia -= d;
	else if(a > d) david -= a;	
}

int main(void){
	
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int a, d;
		scanf("%d %d", &a, &d);
		score(a, d);
	}
	printf("%d\n%d", antonia, david);
	return 0;
}
