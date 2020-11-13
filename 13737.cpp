#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int v[10][11];
	for(int j = 0; j < n; ++j){
		scanf("%d", &v[0][j]);
	}
	int d = 0;
	bool found = false;
	for(int i = 1; i < n; ++i){
		bool flag = true;
		for(int j = 0; j < n - i; ++j){
			v[i][j] = v[i - 1][j + 1] - v[i - 1][j];
			if(v[i][j] != v[i][0]){
				flag = false;
			}
		}
		if(flag && !found){
			d = i;
			found = true;
			v[i][n - i] = v[i][0];
		}
	}
	for(int i = d - 1; i >= 0; --i){
		v[i][n - i] = v[i][n - i - 1] + v[i + 1][n - i - 1];
	}
	printf("%d %d", d, v[0][n]);
	return 0;
}
