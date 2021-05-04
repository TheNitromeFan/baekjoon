#include <iostream>
#define MAX 5000

using namespace std;

void sierpinski(char triangle[][MAX], int n, int x, int y){
	if(n == 1){
		triangle[x][y] = ' ';
		triangle[x][y + 1] = '/';
		triangle[x][y + 2] = '\\';
		triangle[x][y + 3] = ' ';
		triangle[x + 1][y] = '/';
		triangle[x + 1][y + 1] = '_';
		triangle[x + 1][y + 2] = '_';
		triangle[x + 1][y + 3] = '\\';
		return;
	}
	for(int i = x; i < x + (1 << (n - 1)); ++i){
		for(int j = y; j < y + (1 << (n - 1)); ++j){
			triangle[i][j] = ' ';
		}
	}
	for(int i = x; i < x + (1 << (n - 1)); ++i){
		for(int j = y + 3 * (1 << (n - 1)); j < y + (1 << (n + 1)); ++j){
			triangle[i][j] = ' ';
		}
	}
	sierpinski(triangle, n - 1, x, y + (1 << (n - 1)));
	sierpinski(triangle, n - 1, x + (1 << (n - 1)), y);
	sierpinski(triangle, n - 1, x + (1 << (n - 1)), y + (1 << n));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		int n;
		cin >> n;
		if(n == 0){
			break;
		}
		char triangle[MAX][MAX];
		sierpinski(triangle, n, 0, 0);
		for(int i = 0; i < (1 << n); ++i){
			for(int j = 0; j < (1 << n) + i + 1; ++j){
				cout << triangle[i][j];
			}
			cout << '\n';
		}
		cout << '\n';
	}
	return 0;
}
