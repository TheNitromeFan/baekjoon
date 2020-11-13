#include <cstdio>

int main(){
	int z;
	scanf("%d", &z);
	for(int i = 0; i < z; ++i){
		int n;
		scanf("%d", &n);
		int setOf3 = (n - 1) / 3 + 1, placeIn3 = (n - 1) % 3 + 1;
		int shift = setOf3 - 1 + placeIn3 - 1;
		printf("%c\n", 'A' + shift % 4);
	}
	return 0;
}
