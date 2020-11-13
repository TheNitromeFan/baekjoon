#include <cstdio>
#include <limits>

using namespace std;

int main(){
	int n, m;
	scanf("%d\n%d", &n, &m);
	static long long buses[101][101], paths[101][101];
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			buses[i][j] = numeric_limits<long long>::max();
			paths[i][j] = numeric_limits<long long>::max();
			if(i == j){
				paths[i][j] = 0;
			}
		}
	}
	for(int b = 0; b < m; ++b){
		int i, j;
		long long k;
		scanf("%d %d %lld", &i, &j, &k);
		if(k < buses[i][j]){
			buses[i][j] = k;
		}
		paths[i][j] = buses[i][j];
	}
	for(int k = 1; k <= n; ++k){
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= n; ++j){
				if(paths[i][k] != numeric_limits<long long>::max()
				&& paths[k][j] != numeric_limits<long long>::max()
				&& paths[i][j] > paths[i][k] + paths[k][j]){
					paths[i][j] = paths[i][k] + paths[k][j];
				}
			}
		}
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			if(paths[i][j] == numeric_limits<long long>::max()){
				printf("0 ");
			}else{
			    printf("%lld ", paths[i][j]);
			}
		}
		printf("\n");
	}
	return 0;
}
