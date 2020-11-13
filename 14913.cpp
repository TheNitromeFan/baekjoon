#include <cstdio>
#include <cstdlib>

int main(){
	int a, d, k;
	scanf("%d %d %d", &a, &d, &k);
	if((k - a) * d < 0 || abs(k - a) % abs(d) != 0){
		printf("X");
	}else{
		printf("%d", abs(k - a) / abs(d) + 1);
	}
	return 0;
}
