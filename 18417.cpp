#include <cstdio>

void rotate(char src[][501], char dest[][501], int sz){
	for(int i = 0; i < sz; ++i){
		for(int j = 0; j < sz; ++j){
			dest[i][j] = src[j][sz - 1 - i];
		}
	}
}

int changes(char a[][501], char b[][501], int sz){
	int ret = 0;
	for(int i = 0; i < sz; ++i){
		for(int j = 0; j < sz; ++j){
			if(a[i][j] != b[i][j]){
				++ret;
			}
		}
	}
	return ret;
}

int main(){
	char poster[4][501][501], goal[501][501];
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%s", poster[0][i]);
	}
	for(int i = 0; i < n; ++i){
		scanf("%s", goal[i]);
	}
	for(int j = 0; j < 3; ++j){
		rotate(poster[j], poster[j + 1], n);
	}
	int ans = changes(poster[0], goal, n), cmp;
	cmp = changes(poster[1], goal, n) + 1;
	if(ans > cmp){
		ans = cmp;
	}
	cmp = changes(poster[3], goal, n) + 1;
	if(ans > cmp){
		ans = cmp;
	}
	cmp = changes(poster[2], goal, n) + 2;
	if(ans > cmp){
		ans = cmp;
	}
	printf("%d", ans);
	return 0;
}
