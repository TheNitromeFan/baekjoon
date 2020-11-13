#include <cstdio>

bool is_latin(char square[][40], int n){
	for(int i = 0; i < n; ++i){
		int cnt[129] = {};
		for(int j = 0; j < n; ++j){
			++cnt[square[i][j] - '0'];
			if(cnt[square[i][j] - '0'] > 1){
				return false;
			}
		}
	}
	for(int j = 0; j < n; ++j){
		int cnt[129] = {};
		for(int i = 0; i < n; ++i){
			++cnt[square[i][j] - '0'];
			if(cnt[square[i][j] - '0'] > 1){
				return false;
			}
		}
	}
	return true;
}

bool is_reduced(char square[][40], int n){
	for(int j = 0; j < n - 1; ++j){
		if(square[0][j] > square[0][j + 1]){
			return false;
		}
	}
	for(int i = 0; i < n - 1; ++i){
		if(square[i][0] > square[i + 1][0]){
			return false;
		}
	}
	return true;
}

int main(){
	int n;
	scanf("%d", &n);
	char square[40][40];
	for(int i = 0; i < n; ++i){
		scanf("%s", square[i]);
	}
	if(!is_latin(square, n)){
		printf("No");
	}else if(is_reduced(square, n)){
		printf("Reduced");
	}else{
		printf("Not Reduced");
	}
	return 0;
}
