#include <cstdio>
#include <cmath>
#define PI acos(-1)

int main(){
	int a, p1, r, p2;
	scanf("%d %d %d %d", &a, &p1, &r, &p2);
	printf("%s pizza", (a * p2 < PI * r * r * p1) ? "Whole" : "Slice of");
	return 0;
}
