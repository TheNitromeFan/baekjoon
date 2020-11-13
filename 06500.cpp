#include <cstdio>

int nextNum(int num){
	return num * num / 100 % 10000;
}

int main(){
	while(true){
		int n;
		scanf("%d", &n);
		if(n == 0){
			break;
		}
		bool b[10000] = {};
		int cnt = 0;
		while(!b[n]){
			b[n] = true;
			++cnt;
			n = nextNum(n);
		}
		printf("%d\n", cnt);
	}
	return 0;
}
