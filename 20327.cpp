#include <iostream>
#define MAX 300

using namespace std;

void copy_array(int a[][MAX], int b[][MAX], int n){
	for(int x = 0; x < (1 << n); ++x){
		for(int y = 0; y < (1 << n); ++y){
			a[x][y] = b[x][y];
		}
	}
}

void op1(int a[][MAX], int n, int l){
	int b[MAX][MAX];
	for(int x = 0; x < (1 << n); x += (1 << l)){
		for(int y = 0; y < (1 << n); y += (1 << l)){
			for(int i = 0; i < (1 << l); ++i){
				for(int j = 0; j < (1 << l); ++j){
					b[x + i][y + j] = a[x + (1 << l) - 1 - i][y + j];
				}
			}
		}
	}
	copy_array(a, b, n);
}

void op2(int a[][MAX], int n, int l){
	int b[MAX][MAX];
	for(int x = 0; x < (1 << n); x += (1 << l)){
		for(int y = 0; y < (1 << n); y += (1 << l)){
			for(int i = 0; i < (1 << l); ++i){
				for(int j = 0; j < (1 << l); ++j){
					b[x + i][y + j] = a[x + i][y + (1 << l) - 1 - j];
				}
			}
		}
	}
	copy_array(a, b, n);
}

void op3(int a[][MAX], int n, int l){
	int b[MAX][MAX];
	for(int x = 0; x < (1 << n); x += (1 << l)){
		for(int y = 0; y < (1 << n); y += (1 << l)){
			for(int i = 0; i < (1 << l); ++i){
				for(int j = 0; j < (1 << l); ++j){
					b[x + i][y + j] = a[x + (1 << l) - 1 - j][y + i];
				}
			}
		}
	}
	copy_array(a, b, n);
}

void op4(int a[][MAX], int n, int l){
	int b[MAX][MAX];
	for(int x = 0; x < (1 << n); x += (1 << l)){
		for(int y = 0; y < (1 << n); y += (1 << l)){
			for(int i = 0; i < (1 << l); ++i){
				for(int j = 0; j < (1 << l); ++j){
					b[x + i][y + j] = a[x + j][y + (1 << l) - 1 - i];
				}
			}
		}
	}
	copy_array(a, b, n);
}

void op5(int a[][MAX], int n, int l){
	int b[MAX][MAX];
	for(int x = 0; x < (1 << n); x += (1 << l)){
		for(int y = 0; y < (1 << n); y += (1 << l)){
			for(int i = 0; i < (1 << l); ++i){
				for(int j = 0; j < (1 << l); ++j){
					b[x + i][y + j] = a[(1 << n) - (1 << l) - x + i][y + j];
				}
			}
		}
	}
	copy_array(a, b, n);
}

void op6(int a[][MAX], int n, int l){
	int b[MAX][MAX];
	for(int x = 0; x < (1 << n); x += (1 << l)){
		for(int y = 0; y < (1 << n); y += (1 << l)){
			for(int i = 0; i < (1 << l); ++i){
				for(int j = 0; j < (1 << l); ++j){
					b[x + i][y + j] = a[x + i][(1 << n) - (1 << l) - y + j];
				}
			}
		}
	}
	copy_array(a, b, n);
}

void op7(int a[][MAX], int n, int l){
	int b[MAX][MAX];
	for(int x = 0; x < (1 << n); x += (1 << l)){
		for(int y = 0; y < (1 << n); y += (1 << l)){
			for(int i = 0; i < (1 << l); ++i){
				for(int j = 0; j < (1 << l); ++j){
					b[x + i][y + j] = a[(1 << n) - (1 << l) - y + i][x + j];
				}
			}
		}
	}
	copy_array(a, b, n);
}

void op8(int a[][MAX], int n, int l){
	int b[MAX][MAX];
	for(int x = 0; x < (1 << n); x += (1 << l)){
		for(int y = 0; y < (1 << n); y += (1 << l)){
			for(int i = 0; i < (1 << l); ++i){
				for(int j = 0; j < (1 << l); ++j){
					b[x + i][y + j] = a[y + i][(1 << n) - (1 << l) - x + j];
				}
			}
		}
	}
	copy_array(a, b, n);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, r;
	cin >> n >> r;
	int a[MAX][MAX];
	for(int i = 0; i < (1 << n); ++i){
		for(int j = 0 ; j < (1 << n); ++j){
			cin >> a[i][j];
		}
	}
	for(int a0 = 0; a0 < r; ++a0){
		int k, l;
		cin >> k >> l;
		switch(k){
			case 1:
				op1(a, n, l);
				break;
			case 2:
				op2(a, n, l);
				break;
			case 3:
				op3(a, n, l);
				break;
			case 4:
				op4(a, n, l);
				break;
			case 5:
				op5(a, n, l);
				break;
			case 6:
				op6(a, n, l);
				break;
			case 7:
				op7(a, n, l);
				break;
			case 8:
				op8(a, n, l);
				break;
		}
	}
	for(int i = 0; i < (1 << n); ++i){
		for(int j = 0; j < (1 << n); ++j){
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
