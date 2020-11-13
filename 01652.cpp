#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	char tiles[101][101];
	for(int i = 0; i < n; ++i){
		scanf("%s", tiles[i]);
	}
	int cnt1 = 0;
	for(int i = 0; i < n; ++i){
		int spot = 0;
		for(int j = 0; j < n; ++j){
			if(tiles[i][j] == '.'){
				++spot;
				if(spot == 2){
					++cnt1;
				}
			}else{
				spot = 0;
			}
		}
	}
	int cnt2 = 0;
	for(int j = 0; j < n; ++j){
		int spot = 0;
		for(int i = 0; i < n; ++i){
			if(tiles[i][j] == '.'){
				++spot;
				if(spot == 2){
					++cnt2;
				}
			}else{
				spot = 0;
			}
		}
	}
	printf("%d %d", cnt1, cnt2);
	return 0;
}
