#include <cstdio>
#include <algorithm>

using std::max;
using std::min;

void dig(int h[][100], int r, int c, int d){
	int maxHeight = -1000000000;
	for(int i = r - 1; i <= r + 1; ++i){
		for(int j = c - 1; j <= c + 1; ++j){
			maxHeight = max(maxHeight, h[i][j]);
		}
	}
	maxHeight -= d;
	for(int i = r - 1; i <= r + 1; ++i){
		for(int j = c - 1; j <= c + 1; ++j){
			h[i][j] = min(maxHeight, h[i][j]);
		}
	}
}

int main(){
	int hill[100][100];
	int r, c, e, n;
	scanf("%d %d %d %d", &r, &c, &e, &n);
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			scanf("%d", &hill[i][j]);
		}
	}
	for(int s = 0; s < n; ++s){
		int rs, cs, ds;
		scanf("%d %d %d", &rs, &cs, &ds);
		dig(hill, rs, cs, ds);
	}
	long long heights = 0;
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			heights += max(0, e - hill[i][j]);
		}
	}
	printf("%lld", heights * 72 * 72);
	return 0;
}
