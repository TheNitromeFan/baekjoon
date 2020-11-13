#include <cstdio>

bool is_magic(int sq[][5], int sz){
	int cmp = 0;
	for(int j = 0; j < sz; ++j){
		cmp += sq[0][j];
	}
	int sum;
	for(int i = 0; i < sz; ++i){
		sum = 0;
		for(int j = 0; j < sz; ++j){
			sum += sq[i][j];
		}
		if(sum != cmp){
			return false;
		}
	}
	for(int j = 0; j < sz; ++j){
		sum = 0;
		for(int i = 0; i < sz; ++i){
			sum += sq[i][j];
		}
		if(sum != cmp){
			return false;
		}
	}
	sum = 0;
	for(int i = 0; i < sz; ++i){
		sum += sq[i][i];
	}
	if(sum != cmp){
		return false;
	}
	sum = 0;
	for(int i = 0; i < sz; ++i){
		sum += sq[i][sz-1-i];
	}
	if(sum != cmp){
		return false;
	}
	return true;
}

int main(){
	int n;
	scanf("%d", &n);
	for(int a0 = 0; a0 < n; ++a0){
		int m;
		scanf("%d", &m);
		int sq[5][5];
		for(int i = 0; i < m; ++i){
			for(int j = 0; j < m; ++j){
				scanf("%d", &sq[i][j]);
			}
		}
		if(is_magic(sq, m)){
			printf("Magic square of size %d\n", m);
		}else{
			printf("Not a magic square\n");
		}
	}
	return 0;
}
