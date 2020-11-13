#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int max = -1;
	for(int i = 0; i < n; ++i){
		int a;
		scanf("%d", &a);
		if(max < a){
			max = a;
		}
	}
	printf("%d", max);
	return 0;
}
