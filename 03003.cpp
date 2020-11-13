#include <cstdio>

int main(){
	int pieces[6] = {1, 1, 2, 2, 2, 8};
	for(int i = 0; i < 6; ++i){
		int x;
		scanf("%d", &x);
		printf("%d ", pieces[i] - x);
	}
	return 0;
}
