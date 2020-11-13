#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int a = 0, b = 0;
	for(int i = 0; i < n; ++i){
		int ai, bi;
		scanf("%d %d", &ai, &bi);
		if(ai > bi){
			++a;
		}else if(ai < bi){
			++b;
		}
	}
	printf("%d %d", a, b);
	return 0;
}
