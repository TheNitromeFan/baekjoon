#include <cstdio>

int main(){
	int r, c, v, h;
	scanf("%d %d %d %d", &r, &c, &v, &h);
	int rows[51] = {}, cols[51] = {};
	for(int i = 1; i <= v; ++i){
		int x;
		scanf("%d", &x);
		rows[i] = rows[i - 1] + x;
		// printf("%d\n", rows[i]);
	}
	for(int j = 1; j <= h; ++j){
		int y;
		scanf("%d", &y);
		cols[j] = cols[j - 1] + y;
		// printf("%d\n", cols[j]);
	}
	int i1 = 1;
	for(int i = 1; i <= r; ++i){
		int j1 = 1;
		for(int j = 1; j <= c; ++j){
			printf("%c", (i1 + j1) % 2 == 0 ? 'B' : 'W');
			if(j == cols[j1]){
				++j1;
			}
		}
		printf("\n");
		if(i == rows[i1]){
			++i1;
		}
	}
	return 0;
}
