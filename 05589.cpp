#include <iostream>
#include <algorithm>
#define MAX 10000

using namespace std;

void copy_array(int src[][MAX], int dest[][MAX], int rows, int cols){
	for(int row = 0; row < rows; ++row){
		for(int col = 0; col < cols; ++col){
			dest[row][col] = src[row][col];
		}
	}
}

void flip_row(int a[][MAX], int cols, int row){
	for(int col = 0; col < cols; ++col){
		a[row][col] = 1 - a[row][col];
	}
}

int count_stock(int a[][MAX], int rows, int cols){
	int ret = 0;
	for(int col = 0; col < cols; ++col){
		int cnt = 0;
		for(int row = 0; row < rows; ++row){
			if(a[row][col]){
				++cnt;
			}
		}
		ret += max(cnt, rows - cnt);
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int r, c;
	cin >> r >> c;
	int a[10][MAX];
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			cin >> a[i][j];
		}
	}
	int max_stock = 0;
	for(int perm = 0; perm < (1 << r); ++perm){
		int b[10][MAX];
		copy_array(a, b, r, c);
		int x = perm;
		for(int i = 0; i < r; ++i){
			if(x % 2){
				flip_row(b, c, i);
			}
			x /= 2;
		}
		int cmp = count_stock(b, r, c);
		max_stock = max(max_stock, cmp);
	}
	cout << max_stock;
	return 0;
}
