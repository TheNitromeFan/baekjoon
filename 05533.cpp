#include <cstdio>
#include <algorithm>

using std::sort;

bool is_unique(int num[200], int n, int i){
	for(int j = 0; j < n; ++j){
		if(j == i){
			continue;
		}
		if(num[j] == num[i]){
			return false;
		}
	}
	return true;
}

int main(){
	int n;
	scanf("%d", &n);
	int numbers[3][200];
	for(int j = 0; j < n; ++j){
		for(int i = 0; i < 3; ++i){
			scanf("%d", &numbers[i][j]);
		}
	}
	int scores[200] = {};
	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < n; ++j){
			if(is_unique(numbers[i], n, j)){
				scores[j] += numbers[i][j];
			}
		}
	}
	for(int j = 0; j < n; ++j){
		printf("%d\n", scores[j]);
	}
	return 0;
}
