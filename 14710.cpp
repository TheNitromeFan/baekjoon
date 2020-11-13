#include <cstdio>

int main(){
	int theta1, theta2;
	scanf("%d %d", &theta1, &theta2);
	printf("%c", (theta1 % 30) * 12 == theta2 ? 'O' : 'X');
	return 0;
}
