#include <iostream>
#include <algorithm>
#include <functional>
#define MAX 30

using namespace std;

void get_pos(int map[][MAX], int w, int h, int x, int &i, int &j){
	for(i = 0; i < h; ++i){
		for(j = 0; j < w; ++j){
			if(map[i][j] == x){
				return;
			}
		}
	}
}

void swap_rows(int map[][MAX], int w, int row1, int row2){
	for(int j = 0; j < w; ++j){
		swap(map[row1][j], map[row2][j]);
	}
}

void swap_cols(int map[][MAX], int h, int col1, int col2){
	for(int i = 0; i < h; ++i){
		swap(map[i][col1], map[i][col2]);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int form[MAX][MAX];
	int list[MAX * MAX];
	int w, h;
	cin >> w >> h;
	for(int i = 0; i < h; ++i){
		for(int j = 0; j < w; ++j){
			cin >> form[i][j];
			list[i * w + j] = form[i][j];
		}
	}
	sort(list, list + h * w, greater<int>());
	int row = 0, col = 0;
	for(int k = 0; k < w * h; ++k){
		int x = -1, y = -1;
		get_pos(form, w, h, list[k], x, y);
		if(x >= row){
			swap_rows(form, w, row, x);
			++row;
		}
		if(y >= col){
			swap_cols(form, h, col, y);
			++col;
		}
	}
	for(int i = 0; i < h; ++i){
		for(int j = 0; j < w; ++j){
			cout << form[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
