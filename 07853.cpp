#include <iostream>
#include <algorithm>
#define MAX 50
#define MAXSIZE 500

using namespace std;

void draw(char picture[][MAXSIZE], int m, int x, int y, int h, int &picture_height, int &picture_length){
	int posx = 2 * (m - 1 - x) + 4 * y;
	int posy = 2 * (m - 1 - x) + 3 * h;
	// cout << posx << ' ' << posy << '\n';
	picture[posx][posy] = '+';
	picture[posx + 1][posy] = '-';
	picture[posx + 2][posy] = '-';
	picture[posx + 3][posy] = '-';
	picture[posx + 4][posy] = '+';
	picture[posx][posy + 1] = '|';
	picture[posx + 1][posy + 1] = ' ';
	picture[posx + 2][posy + 1] = ' ';
	picture[posx + 3][posy + 1] = ' ';
	picture[posx + 4][posy + 1] = '|';
	picture[posx + 5][posy + 1] = '/';
	picture[posx][posy + 2] = '|';
	picture[posx + 1][posy + 2] = ' ';
	picture[posx + 2][posy + 2] = ' ';
	picture[posx + 3][posy + 2] = ' ';
	picture[posx + 4][posy + 2] = '|';
	picture[posx + 5][posy + 2] = ' ';
	picture[posx + 6][posy + 2] = '+';
	picture[posx][posy + 3] = '+';
	picture[posx + 1][posy + 3] = '-';
	picture[posx + 2][posy + 3] = '-';
	picture[posx + 3][posy + 3] = '-';
	picture[posx + 4][posy + 3] = '+';
	picture[posx + 5][posy + 3] = ' ';
	picture[posx + 6][posy + 3] = '|';
	picture[posx + 1][posy + 4] = '/';
	picture[posx + 2][posy + 4] = ' ';
	picture[posx + 3][posy + 4] = ' ';
	picture[posx + 4][posy + 4] = ' ';
	picture[posx + 5][posy + 4] = '/';
	picture[posx + 6][posy + 4] = '|';
	picture[posx + 2][posy + 5] = '+';
	picture[posx + 3][posy + 5] = '-';
	picture[posx + 4][posy + 5] = '-';
	picture[posx + 5][posy + 5] = '-';
	picture[posx + 6][posy + 5] = '+';
	picture_height = max(picture_height, posy + 5);
	picture_length = max(picture_length, posx + 6);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m, n;
	cin >> m >> n;
	int h[MAX][MAX];
	int max_cube_height = 0;
	for(int i = 0; i < m; ++i){
		for(int j = 0; j < n; ++j){
			cin >> h[i][j];
			max_cube_height = max(max_cube_height, h[i][j]);
		}
	}
	int picture_height = 0, picture_length = 0;
	char picture[MAXSIZE][MAXSIZE];
	for(int i = 0; i < MAXSIZE; ++i){
		for(int j = 0; j < MAXSIZE; ++j){
			picture[i][j] = '.';
		}
	}
	for(int i = 0; i < m; ++i){
		for(int hi = 0; hi < max_cube_height; ++hi){
			for(int j = 0; j < n; ++j){
				if(hi + 1 <= h[i][j]){
					draw(picture, m, i, j, hi, picture_height, picture_length);
				}
			}
		}
	}
	for(int y = picture_height; y >= 0; --y){
		for(int x = 0; x <= picture_length; ++x){
			cout << picture[x][y];
		}
		cout << '\n';
	}
	return 0;
}
