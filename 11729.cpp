#include <cstdio>

void hanoi(int layer, int start, int end, int third){
	if(layer == 1){
		printf("%d %d\n", start, end);
		return;
	}
	hanoi(layer-1, start, third, end);
	printf("%d %d\n", start, end);
	hanoi(layer-1, third, end, start);
}

int main(){
	int n;
	scanf("%d", &n);
	printf("%d\n", (1 << n) - 1);
	hanoi(n, 1, 3, 2);
	return 0;
}
