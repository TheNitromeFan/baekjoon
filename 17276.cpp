#include <iostream>
#include <vector>
#define MAX 510

using namespace std;

void rotate_layer(int a[][MAX], int n, int layer){
	int tmp = a[n / 2 - layer][n / 2 - layer];
	a[n / 2 - layer][n / 2 - layer] = a[n / 2][n / 2 - layer];
	a[n / 2][n / 2 - layer] = a[n / 2 + layer][n / 2 - layer];
	a[n / 2 + layer][n / 2 - layer] = a[n / 2 + layer][n / 2];
	a[n / 2 + layer][n / 2] = a[n / 2 + layer][n / 2 + layer];
	a[n / 2 + layer][n / 2 + layer] = a[n / 2][n / 2 + layer];
	a[n / 2][n / 2 + layer] = a[n / 2 - layer][n / 2 + layer];
	a[n / 2 - layer][n / 2 + layer] = a[n / 2 - layer][n / 2];
	a[n / 2 - layer][n / 2] = tmp;
}

void rotate_45(int a[][MAX], int n){
	for(int i = 1; i <= n / 2; ++i){
		rotate_layer(a, n, i);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int n, d;
		cin >> n >> d;
		int a[MAX][MAX];
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				cin >> a[i][j];
			}
		}
		d = (d + 360) % 360;
		for(int k = 0; k < d; k += 45){
			rotate_45(a, n);
		}
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				cout << a[i][j] << ' ';
			}
			cout << '\n';
		}
	}
	return 0;
}
