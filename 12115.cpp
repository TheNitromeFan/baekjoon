#include <cstdio>

bool compare_rows(int a[][1000], int row[1000], int m, int i){
	for(int j = 0; j < m; ++j){
		if(row[j] == -1){
			continue;
		}
		if(a[i][j] != row[j]){
			return false;
		}
	}
	return true;
}

int main(){
	static int a[1000][1000];
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			scanf("%d", &a[i][j]);
		}
	}
	int q;
	scanf("%d", &q);
	for(int a0 = 0; a0 < q; ++a0){
		int row[1000];
		for(int j = 0; j < m; ++j){
			scanf("%d", &row[j]);
		}
		int cnt = 0;
		for(int i = 0; i < n; ++i){
			if(compare_rows(a, row, m, i)){
				++cnt;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
