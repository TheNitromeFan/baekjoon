#include <cstdio>

int main(){
	bool tulips[15001] = {};
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		int x;
		scanf("%d", &x);
		tulips[x] = true;
	}
	int cnt = 0;
	for(int j = 1; j <= 15000; ++j){
		if(!tulips[j]){
			++cnt;
		}
	}
	printf("%d", cnt);
	return 0;
}
