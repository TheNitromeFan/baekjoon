#include <cstdio>
#include <algorithm>

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	char rect[51][51];
	for(int i = 0; i < n; ++i){
		scanf("%s", rect[i]);
	}
	for(int len = std::min(n, m); len > 0; --len){
		for(int x = 0; x+len-1 < n; ++x){
			for(int y = 0; y+len-1 < m; ++y){
				if(rect[x][y] == rect[x][y+len-1] && rect[x][y] == rect[x+len-1][y] && rect[x][y] == rect[x+len-1][y+len-1]){
					printf("%d", len*len);
					return 0;
				}
			}
		}
	}
}
