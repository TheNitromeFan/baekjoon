#include <iostream>
#include <algorithm>
#include <iomanip>
#define MAX 501

using namespace std;

int find_pivot(double a[][MAX], int n, int col){
	for(int row = col; row <= n; ++row){
		if(a[row][col]){
			return row;
		}
	}
	return -1;
}

void swap_rows(double a[][MAX], int n, int row1, int row2){
	for(int col = 1; col <= n; ++col){
		swap(a[row1][col], a[row2][col]);
	}
}

void scale_row(double a[][MAX], int n, int row, double alpha){
	for(int col = 1; col <= n; ++col){
		a[row][col] /= alpha;
	}
}

void replace_row(double a[][MAX], int n, int row1, int row2, double alpha){
	for(int col = 1; col <= n; ++col){
		a[row1][col] -= alpha * a[row2][col];
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	double a[MAX][MAX];
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			cin >> a[i][j];
		}
	}
	double b[MAX][MAX] = {};
	for(int i = 1; i <= n; ++i){
		b[i][i] = 1;
	}
	for(int j = 1; j <= n; ++j){
		int i = find_pivot(a, n, j);
		if(i == -1){
			cout << "no inverse";
			return 0;
		}
		swap_rows(b, n, i, j);
		swap_rows(a, n, i, j);
		scale_row(b, n, j, a[j][j]);
		scale_row(a, n, j, a[j][j]);
		for(int row = 1; row <= n; ++row){
			if(row == j){
				continue;
			}
			replace_row(b, n, row, j, a[row][j]);
			replace_row(a, n, row, j, a[row][j]);
		}
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			cout << fixed << setprecision(9) << b[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
