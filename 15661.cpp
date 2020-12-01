#include <cstdio>
#include <cstdlib>

int diff(int s[][20], int n, int m){
	int a[20], b[20];
	int i = 0, j = 0;
	int a_sum = 0, b_sum = 0;
	for(int a0 = 0; a0 < n; ++a0){
		if(m % 2 == 0){
			a[i] = a0;
			for(int k = 0; k < i; ++k){
				a_sum += s[a[k]][a[i]] + s[a[i]][a[k]];
			}
			++i;
		}else{
			b[j] = a0;
			for(int k = 0; k < j; ++k){
				b_sum += s[b[k]][b[j]] + s[b[j]][b[k]];
			}
			++j;
		}
		m /= 2;
	}
	return abs(a_sum - b_sum);
}

int main(){
	int n;
	scanf("%d", &n);
	int s[20][20];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			scanf("%d", &s[i][j]);
		}
	}
	int minDiff = 1000000000;
	for(int m = 0; m < (1 << (n - 1)); ++m){
		int cmp = diff(s, n, m);
		if(minDiff > cmp){
			minDiff = cmp;
		}
	}
	printf("%d", minDiff);
	return 0;
}
