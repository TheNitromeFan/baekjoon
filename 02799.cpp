#include <cstdio>
#define MAX 502

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	char windows[MAX][MAX];
	for(int line = 0; line < 5 * n + 1; ++line){
		scanf("%s", windows[line]);
	}
	int ans[5] = {};
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			int state = 0;
			for(int k = 1; k <= 4; ++k){
				if(windows[5 * i + k][5 * j + 1] == '*'){
					++state;
				}else{
					break;
				}
			}
			++ans[state];
		}
	}
	for(int x = 0; x < 5; ++x){
		printf("%d ", ans[x]);
	}
	return 0;
}
