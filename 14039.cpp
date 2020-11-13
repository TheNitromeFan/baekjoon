#include <cstdio>

bool magic(int a[][4]){
	int sum = a[0][0] + a[0][1] + a[0][2] + a[0][3];
	for(int i = 0; i < 4; ++i){
		int s = 0;
		for(int j = 0; j < 4; ++j){
			s += a[i][j];
		}
		if(s != sum){
			return false;
		}
	}
	for(int j = 0; j < 4; ++j){
		int s = 0;
		for(int i = 0; i < 4; ++i){
			s += a[i][j];
		}
		if(s != sum){
			return false;
		}
	}
	return true;
}

int main(){
	int a[4][4];
	for(int i = 0; i < 4; ++i){
		for(int j = 0; j < 4; ++j){
			scanf("%d", &a[i][j]);
		}
	}
	printf("%s", magic(a) ? "magic" : "not magic");
	return 0;
}
