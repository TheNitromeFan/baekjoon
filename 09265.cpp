#include <cstdio>
#define MAX 10000

unsigned parseInt(){
	unsigned ret = 0;
	for(int bit = 0; bit < 32; ++bit){
		char c = getchar();
		ret += (c - '0') * (1U << bit);
	}
 	return ret;
}

int main(){
	unsigned n = parseInt(), m = parseInt();
	unsigned a[MAX][MAX];
	for(unsigned i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			a[i][j] = parseInt();
		}
	}
	unsigned low, high;
	while(cin >> low >> high){
		int ans = 0;
		int left = m - 1, right = m - 1;
		for(int i = 0; i < n; ++i){
			while(left >= 0 && a[i][left] >= low){
				--left;
			}
			while(right >= 0 && a[i][right] > high){
				--right;
			}
			ans += right - left;
		}
		cout << ans << '\n';
	}
	return 0;
}
