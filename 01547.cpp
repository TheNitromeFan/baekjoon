#include <cstdio>
#include <algorithm>

int main(){
	bool ball[4] = {false, true, false, false};
	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; ++i){
		int x, y;
		scanf("%d %d", &x, &y);
		std::swap(ball[x], ball[y]);
	}
	for(int j = 1; j <= 3; ++j){
		if(ball[j]){
			printf("%d", j);
		}
	}
	return 0;
}
