#include <cstdio>

int main(){
	char c[3][4] = {"*x*", " xx", "* *"};
	int k;
	scanf("%d", &k);
	for(int i = 0; i < 3 * k; ++i){
		for(int j = 0; j < 3 * k; ++j){
			printf("%c", c[i / k][j / k]);
		}
		printf("\n");
	}
	return 0;
}
