#include <cstdio>

bool attendedAll(int dinners[][100], int n, int col){
	for(int i = 0; i < n; ++i){
		if(!dinners[i][col]){
			return false;
		}
	}
	return true;
}

bool anyAttendedAll(int dinners[][100], int n, int m){
	for(int j = 0; j < m; ++j){
		if(attendedAll(dinners, n, j)){
			return true;
		}
	}
	return false;
}

int main(){
	while(true){
		int n, d;
		scanf("%d %d", &n, &d);
		if(n == 0 && d == 0){
			break;
		}
		int dinners[500][100];
		for(int i = 0; i < d; ++i){
			for(int j = 0; j < n; ++j){
				scanf("%d", &dinners[i][j]);
			}
		}
		printf("%s\n", anyAttendedAll(dinners, d, n) ? "yes" : "no");
	}
	return 0;
}
