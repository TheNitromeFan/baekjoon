#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	if(n == 1){
		printf("1 bottle of beer on the wall, 1 bottle of beer.\n");
		printf("Take one down and pass it around, no more bottles of beer on the wall.\n\n");
		printf("No more bottles of beer on the wall, no more bottles of beer.\n");
		printf("Go to the store and buy some more, 1 bottle of beer on the wall.");
		return 0;
	}
	for(int i = n; i > 2; --i){
		printf("%d bottles of beer on the wall, %d bottles of beer.\n", i, i);
		printf("Take one down and pass it around, %d bottles of beer on the wall.\n\n", i-1);
	}
	printf("2 bottles of beer on the wall, 2 bottles of beer.\n");
	printf("Take one down and pass it around, 1 bottle of beer on the wall.\n\n");
	printf("1 bottle of beer on the wall, 1 bottle of beer.\n");
	printf("Take one down and pass it around, no more bottles of beer on the wall.\n\n");
	printf("No more bottles of beer on the wall, no more bottles of beer.\n");
	printf("Go to the store and buy some more, %d bottles of beer on the wall.", n);
	return 0;
}
