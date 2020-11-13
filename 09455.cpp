#include <cstdio>
#include <algorithm>
#define MAX 100

using std::swap;

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		int n, m;
		scanf("%d %d", &n, &m);
		int arr[MAX][MAX];
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				scanf("%d", &arr[i][j]);
			}
		}
		int ans = 0;
		for(int j = 0; j < m; ++j){
			int i = n - 1;
			while(i >= 0){
				while(i < n - 1 && arr[i][j] == 1 && arr[i + 1][j] == 0){
					swap(arr[i][j], arr[i + 1][j]);
					++i;
					++ans;
				}
				--i;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
