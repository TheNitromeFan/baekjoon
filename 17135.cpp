#include <cstdio>
#include <cstdlib>
#define MAX 100

using namespace std;

bool live(int a[][MAX], int n, int m){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(a[i][j]){
				return true;
			}
		}
	}
	return false;
}

void advance(int a[][MAX], int n, int m){
	for(int j = 0; j < m; ++j){
		a[n - 1][j] = 0;
	}
	for(int i = n - 2; i >= 0; --i){
		for(int j = 0; j < m; ++j){
			a[i + 1][j] = a[i][j];
			a[i][j] = 0;
		}
	}
}

int target(int a[][MAX], int n, int m, int d, int x, int y, int z){
	bool marked[MAX][MAX] = {};
	for(int dist = 1; dist <= d; ++dist){
		bool found = false;
		for(int j = x - dist + 1; j <= x + dist - 1; ++j){
			int i = n - dist + abs(x - j);
			if(i >= 0 && i < n && j >= 0 && j < m && a[i][j]){
				marked[i][j] = true;
				found = true;
				break;
			}
		}
		if(found){
			break;
		}
	}
	for(int dist = 1; dist <= d; ++dist){
		bool found = false;
		for(int j = y - dist + 1; j <= y + dist - 1; ++j){
			int i = n - dist + abs(y - j);
			if(i >= 0 && i < n && j >= 0 && j < m && a[i][j]){
				marked[i][j] = true;
				found = true;
				break;
			}
		}
		if(found){
			break;
		}
	}
	for(int dist = 1; dist <= d; ++dist){
		bool found = false;
		for(int j = z - dist + 1; j <= z + dist - 1; ++j){
			int i = n - dist + abs(z - j);
			if(i >= 0 && i < n && j >= 0 && j < m && a[i][j]){
				marked[i][j] = true;
				found = true;
				break;
			}
		}
		if(found){
			break;
		}
	}
	int ret = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(marked[i][j]){
				a[i][j] = 0;
				++ret;
			}
		}
	}
	return ret;
}

int main(){
	int n, m, d;
	scanf("%d %d %d", &n, &m, &d);
	int map[MAX][MAX] = {};
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			scanf("%d", &map[i][j]);
		}
	}
	int max = 0;
	for(int x = 0; x < n; ++x){
		for(int y = 0; y < x; ++y){
			for(int z = 0; z < y; ++z){
				int a[MAX][MAX] = {};
				for(int i = 0; i < n; ++i){
					for(int j = 0; j < m; ++j){
						a[i][j] = map[i][j];
					}
				}
				int ans = 0;
				while(live(a, n, m)){
					/*
					for(int i = 0; i < n; ++i){
						for(int j = 0; j < m; ++j){
							printf("%d ", a[i][j]);
						}
						printf("\n");
					}
					printf("\n");
					*/
					ans += target(a, n, m, d, x, y, z);
					advance(a, n, m);
				}
				if(max < ans){
					max = ans;
				}
			}
		}
	}
	printf("%d", max);
	return 0;
}
