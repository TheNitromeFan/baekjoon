#include <cstdio>

int main(){
	int cow[251] = {};
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		cow[i] = i;
	}
	int pos = 1;
	cow[1] = 0;
	while(true){
		int npos = pos * 2;
		if(npos > n){
			npos -= n;
		}
		if(cow[npos] != npos){
			break;
		}
		cow[npos] = pos;
		pos = npos;
	}
	printf("%d", pos);
	return 0;
}
