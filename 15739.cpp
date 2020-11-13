#include <cstdio>
#define MAX 100

bool is_magic(int square[][MAX], int sz){
	int cnt[MAX * MAX + 1] = {};
	for(int i = 0; i < sz; ++i){
		for(int j = 0; j < sz; ++j){
			++cnt[square[i][j]];
			if(cnt[square[i][j]] > 1){
				return false;
			}
		}
	}
	int cmp = sz * (sz * sz + 1) / 2, sum;
	for(int i = 0; i < sz; ++i){
		sum = 0;
		for(int j = 0; j < sz; ++j){
			sum += square[i][j];
		}
		if(sum != cmp){
			return false;
		}
	}
	for(int j = 0; j < sz; ++j){
		sum = 0;
		for(int i = 0; i < sz; ++i){
			sum += square[i][j];
		}
		if(sum != cmp){
			return false;
		}
	}
	sum = 0;
	for(int i = 0; i < sz; ++i){
		sum += square[i][i];
	}
	if(sum != cmp){
		return false;
	}
	sum = 0;
	for(int i = 0, j = sz - 1; i < sz; ++i, --j){
		sum += square[i][j];
	}
	if(sum != cmp){
		return false;
	}
	return true;
}

int main(){
	int n;
	scanf("%d", &n);
	int a[MAX][MAX];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			scanf("%d", &a[i][j]);
		}
	}
	if(is_magic(a, n)){
		printf("TRUE");
	}else{
		printf("FALSE");
	}
	return 0;
}
