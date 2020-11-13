#include <cstdio>

int main(){
	int s, v1, v2;
	scanf("%d %d %d", &s, &v1, &v2);
	for(int i = 0; i * v2 <= s; ++i){
		if((s - i * v2) % v1 == 0){
			printf("%d %d", (s - i * v2) / v1, i);
			return 0;
		}
	}
	printf("Impossible");
	return 0;
}
