#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int sum = 0, points = 0;
	for(int i = 0; i < n; ++i){
		int x;
		scanf("%d", &x);
		if(x == 1){
			++points;
		}else{
			points = 0;
		}
		sum += points;
	}
	printf("%d", sum);
	return 0;
}
