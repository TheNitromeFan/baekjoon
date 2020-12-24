#include <cstdio>
#include <cstdlib>

void op1(int a[][100], int &n, int &m){
	int b[100][100];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			b[i][j] = a[n - 1 - i][j];
		}
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			a[i][j] = b[i][j];
		}
	}
}

void op2(int a[][100], int &n, int &m){
	int b[100][100];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			b[i][j] = a[i][m - 1 - j];
		}
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			a[i][j] = b[i][j];
		}
	}
}

void op3(int a[][100], int &n, int &m){
	int tmp = n;
	n = m;
	m = tmp;
	int b[100][100];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			b[i][j] = a[m - 1 - j][i];
		}
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			a[i][j] = b[i][j];
		}
	}
}

void op4(int a[][100], int &n, int &m){
	int tmp = n;
	n = m;
	m = tmp;
	int b[100][100];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			b[i][j] = a[j][n - 1 - i];
		}
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			a[i][j] = b[i][j];
		}
	}
}

void op5(int a[][100], int &n, int &m){
	int b[100][100];
	for(int i = 0; i < n / 2; ++i){
		for(int j = 0; j < m / 2; ++j){
			b[i][j + m / 2] = a[i][j];
			b[i + n / 2][j + m / 2] = a[i][j + m / 2];
			b[i + n / 2][j] = a[i + n / 2][j + m / 2];
			b[i][j] = a[i + n / 2][j];
		}
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			a[i][j] = b[i][j];
		}
	}
}

void op6(int a[][100], int &n, int &m){
	int b[100][100];
	for(int i = 0; i < n / 2; ++i){
		for(int j = 0; j < m / 2; ++j){
			b[i][j] = a[i][j + m / 2];
			b[i][j + m / 2] = a[i + n / 2][j + m / 2];
			b[i + n / 2][j + m / 2] = a[i + n / 2][j];
			b[i + n / 2][j] = a[i][j];
		}
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			a[i][j] = b[i][j];
		}
	}
}


int main(){
	int n, m, r;
	scanf("%d %d %d", &n, &m, &r);
	int a[100][100] = {};
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			scanf("%d", &a[i][j]);
		}
	}
	int smallRot = 0, bigRot = 0, leftright = false, updown = false;
	for(int k = 0; k < r; ++k){
		int x;
		scanf("%d", &x);
		switch(x){
			case 1:
				updown = !updown;
				break;
			case 2:
				leftright = !leftright;
				break;
			case 3:
				if(updown ^ leftright){
					--smallRot;
				}else{
					++smallRot;
				}
				break;
   			case 4:
				if(updown ^ leftright){
					++smallRot;
				}else{
					--smallRot;
				}
				break;
			case 5:
				if(updown ^ leftright){
					--bigRot;
				}else{
					++bigRot;
				}
				break;
			case 6:
				if(updown ^ leftright){
					++bigRot;
				}else{
					--bigRot;
				}
				break;
		}
	}
	if(smallRot > 0){
		smallRot %= 4;
		for(int i = 0; i < smallRot; ++i){
			op3(a, n, m);
		}
	}else if(smallRot < 0){
		smallRot *= -1;
		smallRot %= 4;
		for(int i = 0; i < smallRot; ++i){
			op4(a, n, m);
		}
	}
	if(bigRot > 0){
		bigRot %= 4;
		for(int i = 0; i < bigRot; ++i){
			op5(a, n, m);
		}
	}else if(bigRot < 0){
		bigRot *= -1;
		bigRot %= 4;
		for(int i = 0; i < bigRot; ++i){
			op6(a, n, m);
		}
	}
	if(updown){
		op1(a, n, m);
	}
	if(leftright){
		op2(a, n, m);
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
