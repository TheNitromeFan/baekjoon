#include <cstdio>

int main(){
	int q;
	scanf("%d", &q);
	for(int i = 0; i < q; ++i){
		int a;
		scanf("%d", &a);
		printf("%d\n", (a & (-a)) == a);
	}
	return 0;
}
