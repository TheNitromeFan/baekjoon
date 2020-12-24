#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#define MAX 55

using namespace std;

void arr_copy(int src[][MAX], int dest[][MAX], int n, int m){
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			dest[i][j] = src[i][j];
		}
	}
}

void rotate_layer(int a[][MAX], int r, int c, int layer){
	int tmp = a[r - layer][c + layer];
	for(int j = c + layer; j > c - layer; --j){
		a[r - layer][j] = a[r - layer][j - 1];
	}
	for(int i = r - layer; i < r + layer; ++i){
		a[i][c - layer] = a[i + 1][c - layer];
	}
	for(int j = c - layer; j < c + layer; ++j){
		a[r + layer][j] = a[r + layer][j + 1];
	}
	for(int i = r + layer; i > r - layer; --i){
		a[i][c + layer] = a[i - 1][c + layer];
	}
	a[r - layer + 1][c + layer] = tmp;
}

void rotate(int a[][MAX], int n, int m, int r, int c, int s){
	for(int k = 1; k <= s; ++k){
		rotate_layer(a, r, c, k);
	}
	/*
	for(int i = 1; i <= 5; ++i){
		for(int j = 1; j <= 6; ++j){
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
	*/
}

int value(int a[][MAX], int n, int m){
	int ret = 1000000000;
	for(int i = 1; i <= n; ++i){
		int sum = 0;
		for(int j = 1; j <= m; ++j){
			sum += a[i][j];
		}
		if(ret > sum){
			ret = sum;
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	int a[MAX][MAX];
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			cin >> a[i][j];
		}
	}
	vector<tuple<int, int, int>> rcs(k);
	for(int p = 0; p < k; ++p){
		int r, c, s;
		cin >> r >> c >> s;
		rcs[p] = make_tuple(r, c, s);
	}
	sort(rcs.begin(), rcs.end());
	int ans = 1000000000;
	do{
		int b[MAX][MAX];
		arr_copy(a, b, n, m);
		for(int p = 0; p < k; ++p){
			rotate(b, n, m, get<0>(rcs[p]), get<1>(rcs[p]), get<2>(rcs[p]));
		}
		int cmp = value(b, n, m);
		if(ans > cmp){
			ans = cmp;
		}
	}while(next_permutation(rcs.begin(), rcs.end()));
	cout << ans;
	return 0;
}
