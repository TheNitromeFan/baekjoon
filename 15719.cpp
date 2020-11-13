#include <cstdio>
#define MAX (10000000 + 1)

int read_int(){
	int ret = 0;
	while(true){
		int c = getchar() - '0';
		if(c < 0 || c > 9){
			return ret;
		}	
		ret = ret * 10 + c;
	}
}

int main(){
	static bool a[MAX] = {};
	int n = read_int();
	for(int i = 0; i <= n; ++i){
		int x = read_int();
		if(a[x]){
			printf("%d", x);
			break;
		}
		a[x] = true;
	}
	return 0;
}
