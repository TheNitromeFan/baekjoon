#include <cstdio>
#include <cstdlib>

int main(){
	int n;
	scanf("%d", &n);
	int sum = 0;
	for(int i = 0; i < 2; ++i){
		for(int j = 0; j < n; ++j){
			int x;
			scanf("%d", &x);
			sum += abs(x);
		}
	}
	printf("%d", sum);
	return 0;
}
