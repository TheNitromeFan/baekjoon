#include <cstdio>
#define MAX 11

int ways(int number){
	int a[MAX] = {0, 1, 2, 4};
	for(int i = 4; i <= number; i++)
		a[i] = a[i-1] + a[i-2] + a[i-3];
	return a[number];
}
int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++){
		int n;
		scanf("%d", &n);
		printf("%d\n", ways(n));
	}
	return 0;
}
