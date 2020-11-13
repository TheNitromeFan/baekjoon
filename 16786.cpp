#include <cstdio>

int main(){
	int squares[2020] = {};
	int n;
	scanf("%d", &n);
	int x[101];
	for(int i = 1; i <= n; ++i){
		scanf("%d", &x[i]);
		squares[x[i]] = i;
	}
	int m;
	scanf("%d", &m);
	for(int j = 1; j <= m; ++j){
		int aj;
		scanf("%d", &aj);
		if(x[aj] < 2019 && squares[x[aj] + 1] == 0){
			squares[x[aj]] = 0;
			++x[aj];
			squares[x[aj]] = aj;
		}
	}
	for(int i = 1; i <= n; ++i){
		printf("%d\n", x[i]);
	}
	return 0;
}
