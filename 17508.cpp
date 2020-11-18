#include <cstdio>

int rotations(char cards[][501], int n, int m){
	if(n % 2 == 1 && m % 2 == 1 && cards[n / 2][m / 2] != '8'){
		return -1;
	}
	int cnt = 0;
	if(n % 2 == 1){
		for(int j1 = 0, j2 = m - 1; j1 < j2; ++j1, --j2){
			if((cards[n / 2][j1] == '8' && cards[n / 2][j2] == '8')
			|| (cards[n / 2][j1] == '6' && cards[n / 2][j2] == '9')
			|| (cards[n / 2][j1] == '9' && cards[n / 2][j2] == '6'));
			else if(cards[n / 2][j1] == cards[n / 2][j2]){
				++cnt;
			}else{
				return -1;
			}
		}
	}
	for(int i1 = 0, i2 = n - 1; i1 < i2; ++i1, --i2){
		for(int j1 = 0, j2 = m - 1; j1 < m; ++j1, --j2){
			if((cards[i1][j1] == '8' && cards[i2][j2] == '8')
			|| (cards[i1][j1] == '6' && cards[i2][j2] == '9')
			|| (cards[i1][j1] == '9' && cards[i2][j2] == '6'));
			else if(cards[i1][j1] == cards[i2][j2]){
				++cnt;
			}else{
				return -1;
			}
		}
	}
	return cnt;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	char cards[501][501];
	for(int i = 0; i < n; ++i){
		scanf("%s", cards[i]);
	}
	printf("%d", rotations(cards, n, m));
	return 0;
}
