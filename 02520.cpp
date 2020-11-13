#include <cstdio>
#include <algorithm>

using std::min;

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		int milk, yolk, sugar, salt, flour;
		scanf("%d %d %d %d %d", &milk, &yolk, &sugar, &salt, &flour);
		int dough = min(min(min(min(2 * milk, 2 * yolk), 4 * sugar), 16 * salt), 16 * flour / 9);
		int banana, strawberry, chocolate, walnut;
		scanf("%d %d %d %d", &banana, &strawberry, &chocolate, &walnut);
		printf("%d\n", min(dough, banana + strawberry / 30 + chocolate / 25 + walnut / 10));
	}
	return 0;
}
