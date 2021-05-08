#include <iostream>
#define MAX 1010

using namespace std;

void rotate(int a[][MAX], int n, int r){
	int tmp = a[r - 1][r - 1];
	for(int j = r - 1; j < n - r; ++j){
		a[r - 1][j] = a[r - 1][j + 1];
	}
	for(int i = r - 1; i < n - r; ++i){
		a[i][n - r] = a[i + 1][n - r];
	}
	for(int j = n - r; j > r - 1; --j){
		a[n - r][j] = a[n - r][j - 1];
	}
	for(int i = n - r; i > r; --i){
		a[i][r - 1] = a[i - 1][r - 1];
	}
	a[r][r - 1] = tmp;
	/*
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
	*/
}

bool ring(int a[][MAX], int n){
	for(int r = 1; r <= (n + 1) / 2; ++r){
		int top_left = (r - 1) * n + r;
		int x = -1, y = -1;
		for(int j = r - 1; j <= n - r; ++j){
			if(a[r - 1][j] == top_left){
				x = r - 1;
				y = j;
				break;
			}else if(a[n - r][j] == top_left){
				x = n - r;
				y = j;
				break;
			}
		}
		for(int i = r - 1; i <= n - r; ++i){
			if(a[i][r - 1] == top_left){
				x = i;
				y = r - 1;
				break;
			}else if(a[i][n - r] == top_left){
				x = i;
				y = n - r;
				break;
			}
		}
		if(x == -1 && y == -1){
			return false;
		}
		while(a[r - 1][r - 1] != top_left){
			rotate(a, n, r);
		}
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(a[i][j] != n * i + j + 1){
				return false;
			}
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc = 0;
	while(true){
		int n;
		cin >> n;
		if(n == 0){
			break;
		}
		++tc;
		int arr[MAX][MAX];
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				cin >> arr[i][j];
			}
		}
		cout << tc << ". " << (ring(arr, n) ? "YES" : "NO") << "\n";
	}
	return 0;
}
