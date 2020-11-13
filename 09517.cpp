#include <cstdio>
#define TIME_LIMIT (3 * 60 + 30)

int main(){
	int k;
	scanf("%d", &k);
	int n;
	scanf("%d", &n);
	int time = 0;
	for(int i = 0; i < n; ++i){
		int t;
		char z;
		scanf("%d %c", &t, &z);
		time += t;
		if(time > TIME_LIMIT){
			break;
		}
		if(z == 'T'){
			k = k % 8 + 1;
		}
	}
	printf("%d", k);
	return 0;
}
