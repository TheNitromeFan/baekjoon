#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int h[10];
	for(int i = 0; i < n; ++i){
		scanf("%d", &h[i]);
	}
	int t;
	scanf("%d", &t);
	int setting = h[0];
	for(int i = 1; i < n; ++i){
		if(t % h[i] < t % setting){
			setting = h[i];
		}
	}
	printf("%d", setting);
	return 0;
}
