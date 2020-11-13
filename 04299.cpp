#include <cstdio>

int main(){
	int s, d;
	scanf("%d %d", &s, &d);
	if(s >= d && s % 2 == d % 2){
		printf("%d %d", (s + d) / 2, (s - d) / 2);
	}else{
		printf("-1");
	}
	return 0;
}
